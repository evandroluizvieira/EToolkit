/**
 * @file StaticArrayTest.cpp
 * @brief Defines the tests for the EToolkit static array.
 */

#include "StaticArrayTest.hpp"
#include "TestAssertions.hpp"

#include <EContainer>
#include <EException>

#include <utility>

bool StaticArrayTest::run(){
    const EToolkitTest::TestCase tests[] = {
        {"StaticArray construction and access", testConstructionAndAccess},
        {"StaticArray mutation and clear", testMutationAndClear},
        {"StaticArray iteration and const correctness", testIterationAndConstCorrectness},
        {"StaticArray bounds checking", testBoundsChecking}
    };
    return EToolkitTest::runSuite("StaticArrayTest", tests);
}

bool StaticArrayTest::testConstructionAndAccess(){
    EToolkit::StaticArray<int, unsigned int, 3> values{1, 2, 3};

    ETOOLKIT_TEST_ASSERT("static array size", values.getSize() == 3);
    ETOOLKIT_TEST_ASSERT("static array front", values.getFront() == 1);
    ETOOLKIT_TEST_ASSERT("static array back", values.getBack() == 3);
    ETOOLKIT_TEST_ASSERT("static array at", values.at(1) == 2);
    ETOOLKIT_TEST_ASSERT("static array contains existing value", values.contains(2));
    ETOOLKIT_TEST_ASSERT("static array rejects missing value", !values.contains(4));
    return true;
}

bool StaticArrayTest::testMutationAndClear(){
    EToolkit::StaticArray<int, unsigned int, 3> values{1, 2, 3};
    EToolkit::StaticArray<int, unsigned int, 3> copy(values);
    ETOOLKIT_TEST_ASSERT("static array copy", copy == values);

    EToolkit::StaticArray<int, unsigned int, 3> moved(std::move(values));
    EToolkit::StaticArray<int, unsigned int, 3> assigned;
    assigned = std::move(moved);
    EToolkit::StaticArray<int, unsigned int, 3>& valuesReference = assigned;

    valuesReference.swap(0, 2);
    ETOOLKIT_TEST_ASSERT("static array swap first", valuesReference[0] == 3);
    ETOOLKIT_TEST_ASSERT("static array swap last", valuesReference[2] == 1);

    valuesReference.fill(7);
    ETOOLKIT_TEST_ASSERT("static array fill", valuesReference.isEqual(EToolkit::StaticArray<int, unsigned int, 3>{7, 7, 7}));

    valuesReference.clear();
    ETOOLKIT_TEST_ASSERT("static array clear size", valuesReference.getSize() == 3);
    ETOOLKIT_TEST_ASSERT("static array clear first", valuesReference[0] == 0);
    ETOOLKIT_TEST_ASSERT("static array clear middle", valuesReference[1] == 0);
    ETOOLKIT_TEST_ASSERT("static array clear last", valuesReference[2] == 0);
    return true;
}

bool StaticArrayTest::testIterationAndConstCorrectness(){
    EToolkit::StaticArray<int, unsigned int, 3> values{1, 2, 3};
    const EToolkit::StaticArray<int, unsigned int, 3>& constValues = values;

    ETOOLKIT_TEST_ASSERT("static array begin", values.begin() == values.getData());
    ETOOLKIT_TEST_ASSERT("static array end", values.end() == values.getData() + values.getSize());
    ETOOLKIT_TEST_ASSERT("static array const data", constValues.getData()[0] == 1);
    ETOOLKIT_TEST_ASSERT("static array const begin", constValues.cbegin() == constValues.getData());
    ETOOLKIT_TEST_ASSERT("static array const end", constValues.cend() == constValues.getData() + constValues.getSize());
    return true;
}

bool StaticArrayTest::testBoundsChecking(){
    EToolkit::StaticArray<int, unsigned int, 3> values;
    bool threw = false;

    try{
        values.at(3);
    }catch(const EToolkit::OutOfBoundsException&){
        threw = true;
    }

    ETOOLKIT_TEST_ASSERT("static array throws on invalid index", threw);
    return true;
}
