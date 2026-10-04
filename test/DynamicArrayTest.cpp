/**
 * @file DynamicArrayTest.cpp
 * @brief Defines the tests for the EToolkit dynamic array.
 */

#include "DynamicArrayTest.hpp"
#include "TestAssertions.hpp"

#include <EContainer>
#include <EException>

#include <utility>

bool DynamicArrayTest::run(){
    const EToolkitTest::TestCase tests[] = {
        {"DynamicArray construction and insertion", testConstructionAndInsertion},
        {"DynamicArray resize and removal", testResizeAndRemoval},
        {"DynamicArray copy, comparison, and iteration", testCopyComparisonAndIteration},
        {"DynamicArray bounds checking", testBoundsChecking}
    };
    return EToolkitTest::runSuite("DynamicArrayTest", tests);
}

bool DynamicArrayTest::testConstructionAndInsertion(){
    EToolkit::DynamicArray<int> values;

    ETOOLKIT_TEST_ASSERT("dynamic array initial size", values.getSize() == 0);
    ETOOLKIT_TEST_ASSERT("dynamic array initial capacity", values.getCapacity() >= 2);
    ETOOLKIT_TEST_ASSERT("dynamic array initially empty", values.isEmpty());

    values.insertBack(2);
    values.insertFront(1);
    values.insert(3, values.getSize());

    ETOOLKIT_TEST_ASSERT("dynamic array insertion size", values.getSize() == 3);
    ETOOLKIT_TEST_ASSERT("dynamic array insertion front", values.getFront() == 1);
    ETOOLKIT_TEST_ASSERT("dynamic array insertion back", values.getBack() == 3);
    return true;
}

bool DynamicArrayTest::testResizeAndRemoval(){
    EToolkit::DynamicArray<int> values;
    values.insertBack(1);
    values.insertBack(2);
    values.insertBack(3);

    values.reserve(16);
    ETOOLKIT_TEST_ASSERT("dynamic array reserve", values.getCapacity() >= 16);

    values.resize(5);
    ETOOLKIT_TEST_ASSERT("dynamic array resize size", values.getSize() == 5);
    ETOOLKIT_TEST_ASSERT("dynamic array resize initializes values", values[3] == 0);

    values.removeFront();
    values.removeBack();
    ETOOLKIT_TEST_ASSERT("dynamic array removal size", values.getSize() == 3);
    ETOOLKIT_TEST_ASSERT("dynamic array removal front", values[0] == 2);

    values.clear();
    values.removeBack();
    values.insertBack(42);
    values.removeBack();
    values.insertBack(43);
    ETOOLKIT_TEST_ASSERT("dynamic array clear and reuse size", values.getSize() == 1);
    ETOOLKIT_TEST_ASSERT("dynamic array clear and reuse value", values.getFront() == 43);
    return true;
}

bool DynamicArrayTest::testCopyComparisonAndIteration(){
    EToolkit::DynamicArray<int> values;
    values.insertBack(1);
    values.insertBack(2);

    EToolkit::DynamicArray<int> copy(values);
    ETOOLKIT_TEST_ASSERT("dynamic array copy", copy == values);

    const EToolkit::DynamicArray<int>& constCopy = copy;
    const EToolkit::DynamicArray<int>& constValuesForComparison = values;
    ETOOLKIT_TEST_ASSERT("dynamic array const equality", constCopy == constValuesForComparison);
    ETOOLKIT_TEST_ASSERT("dynamic array const inequality", !(constCopy != constValuesForComparison));

    copy += 9;
    ETOOLKIT_TEST_ASSERT("dynamic array mutation changes comparison", copy != values);
    copy = values;
    ETOOLKIT_TEST_ASSERT("dynamic array assignment", copy == values);

    EToolkit::DynamicArray<int> moved(std::move(copy));
    ETOOLKIT_TEST_ASSERT("dynamic array move construction", moved == values);

    EToolkit::DynamicArray<int> assigned;
    assigned = std::move(moved);
    ETOOLKIT_TEST_ASSERT("dynamic array move assignment", assigned == values);

    const EToolkit::DynamicArray<int>& constValues = values;
    ETOOLKIT_TEST_ASSERT("dynamic array const data", constValues.getData() == values.getData());
    ETOOLKIT_TEST_ASSERT("dynamic array const begin", constValues.cbegin() == constValues.getData());
    ETOOLKIT_TEST_ASSERT("dynamic array const end", constValues.cend() == constValues.getData() + constValues.getSize());
    return true;
}

bool DynamicArrayTest::testBoundsChecking(){
    EToolkit::DynamicArray<int> values;
    values.insertBack(1);
    bool threw = false;

    try{
        values.get(1);
    }catch(const EToolkit::OutOfBoundsException&){
        threw = true;
    }

    ETOOLKIT_TEST_ASSERT("dynamic array throws on invalid index", threw);
    return true;
}
