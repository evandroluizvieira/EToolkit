/**
 * @file DynamicArrayTest.cpp
 * @brief Defines the tests for the EToolkit dynamic array.
 */

#include "DynamicArrayTest.hpp"
#include "TestAssertions.hpp"

#include <EContainer>
#include <EException>

#include <utility>

void DynamicArrayTest::run(){
    testConstructionAndInsertion();
    testResizeAndRemoval();
    testCopyComparisonAndIteration();
    testBoundsChecking();
}

void DynamicArrayTest::testConstructionAndInsertion(){
    EToolkit::DynamicArray<int> values;

    ETOOLKIT_TEST_ASSERT(values.getSize() == 0);
    ETOOLKIT_TEST_ASSERT(values.getCapacity() >= 2);
    ETOOLKIT_TEST_ASSERT(values.isEmpty());

    values.insertBack(2);
    values.insertFront(1);
    values.insert(3, values.getSize());

    ETOOLKIT_TEST_ASSERT(values.getSize() == 3);
    ETOOLKIT_TEST_ASSERT(values.getFront() == 1);
    ETOOLKIT_TEST_ASSERT(values.getBack() == 3);
}

void DynamicArrayTest::testResizeAndRemoval(){
    EToolkit::DynamicArray<int> values;
    values.insertBack(1);
    values.insertBack(2);
    values.insertBack(3);

    values.reserve(16);
    ETOOLKIT_TEST_ASSERT(values.getCapacity() >= 16);

    values.resize(5);
    ETOOLKIT_TEST_ASSERT(values.getSize() == 5);
    ETOOLKIT_TEST_ASSERT(values[3] == 0);

    values.removeFront();
    values.removeBack();
    ETOOLKIT_TEST_ASSERT(values.getSize() == 3);
    ETOOLKIT_TEST_ASSERT(values[0] == 2);

    values.clear();
    values.removeBack();
    values.insertBack(42);
    values.removeBack();
    values.insertBack(43);
    ETOOLKIT_TEST_ASSERT(values.getSize() == 1);
    ETOOLKIT_TEST_ASSERT(values.getFront() == 43);
}

void DynamicArrayTest::testCopyComparisonAndIteration(){
    EToolkit::DynamicArray<int> values;
    values.insertBack(1);
    values.insertBack(2);

    EToolkit::DynamicArray<int> copy(values);
    ETOOLKIT_TEST_ASSERT(copy == values);

    const EToolkit::DynamicArray<int>& constCopy = copy;
    const EToolkit::DynamicArray<int>& constValuesForComparison = values;
    ETOOLKIT_TEST_ASSERT(constCopy == constValuesForComparison);
    ETOOLKIT_TEST_ASSERT(!(constCopy != constValuesForComparison));

    copy += 9;
    ETOOLKIT_TEST_ASSERT(copy != values);
    copy = values;
    ETOOLKIT_TEST_ASSERT(copy == values);

    EToolkit::DynamicArray<int> moved(std::move(copy));
    ETOOLKIT_TEST_ASSERT(moved == values);

    EToolkit::DynamicArray<int> assigned;
    assigned = std::move(moved);
    ETOOLKIT_TEST_ASSERT(assigned == values);

    const EToolkit::DynamicArray<int>& constValues = values;
    ETOOLKIT_TEST_ASSERT(constValues.getData() == values.getData());
    ETOOLKIT_TEST_ASSERT(constValues.cbegin() == constValues.getData());
    ETOOLKIT_TEST_ASSERT(constValues.cend() == constValues.getData() + constValues.getSize());
}

void DynamicArrayTest::testBoundsChecking(){
    EToolkit::DynamicArray<int> values;
    values.insertBack(1);
    bool threw = false;

    try{
        values.get(1);
    }catch(const EToolkit::OutOfBoundsException&){
        threw = true;
    }

    ETOOLKIT_TEST_ASSERT(threw);
}
