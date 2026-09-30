/**
 * @file StaticArrayTest.cpp
 * @brief Defines the tests for the EToolkit static array.
 */

#include "StaticArrayTest.hpp"
#include "TestAssertions.hpp"

#include <EContainer>
#include <EException>

#include <utility>

void StaticArrayTest::run(){
    testConstructionAndAccess();
    testMutationAndClear();
    testIterationAndConstCorrectness();
    testBoundsChecking();
}

void StaticArrayTest::testConstructionAndAccess(){
    EToolkit::StaticArray<int, unsigned int, 3> values{1, 2, 3};

    ETOOLKIT_TEST_ASSERT(values.getSize() == 3);
    ETOOLKIT_TEST_ASSERT(values.getFront() == 1);
    ETOOLKIT_TEST_ASSERT(values.getBack() == 3);
    ETOOLKIT_TEST_ASSERT(values.at(1) == 2);
    ETOOLKIT_TEST_ASSERT(values.contains(2));
    ETOOLKIT_TEST_ASSERT(!values.contains(4));
}

void StaticArrayTest::testMutationAndClear(){
    EToolkit::StaticArray<int, unsigned int, 3> values{1, 2, 3};
    EToolkit::StaticArray<int, unsigned int, 3> moved(std::move(values));
    EToolkit::StaticArray<int, unsigned int, 3> assigned;
    assigned = std::move(moved);
    EToolkit::StaticArray<int, unsigned int, 3>& valuesReference = assigned;

    valuesReference.swap(0, 2);
    ETOOLKIT_TEST_ASSERT(valuesReference[0] == 3);
    ETOOLKIT_TEST_ASSERT(valuesReference[2] == 1);

    valuesReference.fill(7);
    ETOOLKIT_TEST_ASSERT(valuesReference.isEqual(EToolkit::StaticArray<int, unsigned int, 3>{7, 7, 7}));

    valuesReference.clear();
    ETOOLKIT_TEST_ASSERT(valuesReference.getSize() == 3);
    ETOOLKIT_TEST_ASSERT(valuesReference[0] == 0);
    ETOOLKIT_TEST_ASSERT(valuesReference[1] == 0);
    ETOOLKIT_TEST_ASSERT(valuesReference[2] == 0);
}

void StaticArrayTest::testIterationAndConstCorrectness(){
    EToolkit::StaticArray<int, unsigned int, 3> values{1, 2, 3};
    const EToolkit::StaticArray<int, unsigned int, 3>& constValues = values;

    ETOOLKIT_TEST_ASSERT(values.begin() == values.getData());
    ETOOLKIT_TEST_ASSERT(values.end() == values.getData() + values.getSize());
    ETOOLKIT_TEST_ASSERT(constValues.getData()[0] == 1);
    ETOOLKIT_TEST_ASSERT(constValues.cbegin() == constValues.getData());
    ETOOLKIT_TEST_ASSERT(constValues.cend() == constValues.getData() + constValues.getSize());
}

void StaticArrayTest::testBoundsChecking(){
    EToolkit::StaticArray<int, unsigned int, 3> values;
    bool threw = false;

    try{
        values.at(3);
    }catch(const EToolkit::OutOfBoundsException&){
        threw = true;
    }

    ETOOLKIT_TEST_ASSERT(threw);
}
