/**
 * @file ContainerInterfaceTest.cpp
 * @brief Defines tests for `EToolkit::IContainer` behavior through concrete containers.
 */

#include "ContainerInterfaceTest.hpp"
#include "TestAssertions.hpp"

#include <EContainer>

/**
 * @brief Minimal concrete container used only to validate `IContainer` behavior.
 * @implements EToolkit::IContainer<int, unsigned int>
 */
class ContainerInterfaceStub final : public EToolkit::IContainer<int, unsigned int>{
    public:
        /**
         * @brief Constructs an empty container view.
         */
        ContainerInterfaceStub()
            : size(0), data(nullptr){
        }

        /**
         * @brief Constructs a container view from existing values.
         * @param values source values
         * @param count number of values
         */
        ContainerInterfaceStub(int* values, unsigned int count)
            : size(count), data(values){
        }

        /**
         * @brief Destroys the stub instance.
         */
        ~ContainerInterfaceStub() override = default;

        /**
         * @brief Returns the current number of values.
         * @return current size
         */
        unsigned int getSize() const override{
            return size;
        }

        /**
         * @brief Returns immutable data pointer.
         * @return immutable data pointer
         */
        const int* getData() const override{
            return data;
        }

        /**
         * @brief Returns mutable data pointer.
         * @return mutable data pointer
         */
        int* getData() override{
            return data;
        }

        /**
         * @brief Clears size and data pointers.
         */
        void clear() override{
            size = 0;
            data = nullptr;
        }

        /**
         * @brief Swaps this instance with another compatible stub.
         * @param other other container interface
         */
        void swap(EToolkit::IContainer<int, unsigned int>& other) override{
            ContainerInterfaceStub* otherStub = dynamic_cast<ContainerInterfaceStub*>(&other);
            if(otherStub == nullptr){
                return;
            }

            int* temporaryData = data;
            data = otherStub->data;
            otherStub->data = temporaryData;

            unsigned int temporarySize = size;
            size = otherStub->size;
            otherStub->size = temporarySize;
        }

        /**
         * @brief Forces a non-empty state with null data for safety-path tests.
         * @param count forced size value
         */
        void forceNullData(unsigned int count){
            size = count;
            data = nullptr;
        }

    private:
        unsigned int size;	///< Number of values.
        int*         data;	///< Pointer to values.
};

/**
 * @brief Incompatible container implementation for swap behavior checks.
 * @implements EToolkit::IContainer<int, unsigned int>
 */
class IncompatibleContainerStub final : public EToolkit::IContainer<int, unsigned int>{
    public:
        /**
         * @brief Constructs an empty incompatible stub.
         */
        IncompatibleContainerStub()
            : size(0), value(0){
        }

        /**
         * @brief Destroys the incompatible stub.
         */
        ~IncompatibleContainerStub() override = default;

        /**
         * @brief Returns current size.
         * @return current size
         */
        unsigned int getSize() const override{
            return size;
        }

        /**
         * @brief Returns immutable data pointer.
         * @return immutable data pointer
         */
        const int* getData() const override{
            return size == 0 ? nullptr : &value;
        }

        /**
         * @brief Returns mutable data pointer.
         * @return mutable data pointer
         */
        int* getData() override{
            return size == 0 ? nullptr : &value;
        }

        /**
         * @brief Clears current state.
         */
        void clear() override{
            size = 0;
            value = 0;
        }

        /**
         * @brief Leaves this stub unchanged when asked to swap.
         * @param other Container ignored by this test stub.
         */
        void swap(EToolkit::IContainer<int, unsigned int>& other) override{
            (void)other;
        }

        /**
         * @brief Sets one stored value.
         * @param input Value to store.
         */
        void setOneValue(int input){
            size = 1;
            value = input;
        }

    private:
        unsigned int size;	///< Number of values.
        int          value;	///< Stored value.
};

bool ContainerInterfaceTest::run(){
    const EToolkitTest::TestCase tests[] = {
        {"IContainer empty-state behavior", testEmptyState},
        {"IContainer equality and inequality", testEqualityAndInequality},
        {"IContainer size and self-comparison", testSizeAndSelfComparison},
        {"IContainer clear and swap behavior", testClearAndSwap},
        {"IContainer null-data safety", testNullDataSafety},
        {"IContainer incompatible swap behavior", testSwapWithIncompatibleImplementation}
    };
    return EToolkitTest::runSuite("ContainerInterfaceTest", tests);
}

bool ContainerInterfaceTest::testEmptyState(){
    int emptyValues[1] = {0};
    ContainerInterfaceStub empty(emptyValues, 0);
    EToolkit::IContainer<int, unsigned int>& container = empty;

    ETOOLKIT_TEST_ASSERT("icontainer initial empty state", container.isEmpty());

    int singleValue[1] = {10};
    ContainerInterfaceStub nonEmpty(singleValue, 1);
    EToolkit::IContainer<int, unsigned int>& nonEmptyContainer = nonEmpty;
    ETOOLKIT_TEST_ASSERT("icontainer non-empty state", !nonEmptyContainer.isEmpty());
    ETOOLKIT_TEST_ASSERT("icontainer size after insertion", nonEmptyContainer.getSize() == 1);
    return true;
}

bool ContainerInterfaceTest::testEqualityAndInequality(){
    int leftData[2] = {1, 2};
    int rightData[2] = {1, 2};
    int differentData[2] = {1, 3};

    ContainerInterfaceStub left(leftData, 2);
    ContainerInterfaceStub right(rightData, 2);
    ContainerInterfaceStub different(differentData, 2);

    const EToolkit::IContainer<int, unsigned int>& leftInterface = left;
    const EToolkit::IContainer<int, unsigned int>& rightInterface = right;
    const EToolkit::IContainer<int, unsigned int>& differentInterface = different;

    ETOOLKIT_TEST_ASSERT("icontainer equality true", leftInterface == rightInterface);
    ETOOLKIT_TEST_ASSERT("icontainer inequality false for equal values", !(leftInterface != rightInterface));
    ETOOLKIT_TEST_ASSERT("icontainer inequality true for different values", leftInterface != differentInterface);
    return true;
}

bool ContainerInterfaceTest::testSizeAndSelfComparison(){
    int oneValue[1] = {42};
    int twoValues[2] = {42, 100};

    ContainerInterfaceStub one(oneValue, 1);
    ContainerInterfaceStub two(twoValues, 2);

    const EToolkit::IContainer<int, unsigned int>& oneInterface = one;
    const EToolkit::IContainer<int, unsigned int>& twoInterface = two;

    ETOOLKIT_TEST_ASSERT("icontainer inequality on different sizes", oneInterface != twoInterface);
    ETOOLKIT_TEST_ASSERT("icontainer self equality", oneInterface == oneInterface);
    ETOOLKIT_TEST_ASSERT("icontainer self inequality false", !(oneInterface != oneInterface));
    return true;
}

bool ContainerInterfaceTest::testClearAndSwap(){
    int leftData[2] = {7, 8};
    int rightData[1] = {3};

    ContainerInterfaceStub left(leftData, 2);
    ContainerInterfaceStub right(rightData, 1);

    EToolkit::IContainer<int, unsigned int>& leftInterface = left;
    EToolkit::IContainer<int, unsigned int>& rightInterface = right;

    leftInterface.swap(rightInterface);
    ETOOLKIT_TEST_ASSERT("icontainer swap left size", leftInterface.getSize() == 1);
    ETOOLKIT_TEST_ASSERT("icontainer swap right size", rightInterface.getSize() == 2);
    ETOOLKIT_TEST_ASSERT("icontainer swap left first element", leftInterface.getData()[0] == 3);
    ETOOLKIT_TEST_ASSERT("icontainer swap right first element", rightInterface.getData()[0] == 7);

    leftInterface.clear();
    ETOOLKIT_TEST_ASSERT("icontainer clear empties container", leftInterface.isEmpty());
    ETOOLKIT_TEST_ASSERT("icontainer clear resets size", leftInterface.getSize() == 0);
    leftInterface.clear();
    ETOOLKIT_TEST_ASSERT("icontainer clear is idempotent", leftInterface.getSize() == 0);
    return true;
}

bool ContainerInterfaceTest::testNullDataSafety(){
    int oneValue[1] = {5};
    ContainerInterfaceStub valid(oneValue, 1);
    ContainerInterfaceStub invalid;
    invalid.forceNullData(1);

    const EToolkit::IContainer<int, unsigned int>& validInterface = valid;
    const EToolkit::IContainer<int, unsigned int>& invalidInterface = invalid;

    ETOOLKIT_TEST_ASSERT("icontainer null-data path is unequal", validInterface != invalidInterface);
    ETOOLKIT_TEST_ASSERT("icontainer null-data does not equal valid data", !(validInterface == invalidInterface));

    ContainerInterfaceStub emptyA;
    ContainerInterfaceStub emptyB;
    const EToolkit::IContainer<int, unsigned int>& emptyAInterface = emptyA;
    const EToolkit::IContainer<int, unsigned int>& emptyBInterface = emptyB;
    ETOOLKIT_TEST_ASSERT("icontainer empty containers equal even with null data", emptyAInterface == emptyBInterface);
    return true;
}

bool ContainerInterfaceTest::testSwapWithIncompatibleImplementation(){
    int values[2] = {9, 10};
    ContainerInterfaceStub compatible(values, 2);
    IncompatibleContainerStub incompatible;
    incompatible.setOneValue(100);

    EToolkit::IContainer<int, unsigned int>& compatibleInterface = compatible;
    EToolkit::IContainer<int, unsigned int>& incompatibleInterface = incompatible;

    compatibleInterface.swap(incompatibleInterface);
    ETOOLKIT_TEST_ASSERT("icontainer swap with incompatible keeps size", compatibleInterface.getSize() == 2);
    ETOOLKIT_TEST_ASSERT("icontainer swap with incompatible keeps first value", compatibleInterface.getData()[0] == 9);
    return true;
}

ETOOLKIT_REGISTER_TEST_SUITE(ContainerInterfaceTest)
