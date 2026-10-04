#include "GeometryTest.hpp"
#include "TestAssertions.hpp"

#include <EBounds>

namespace{

bool testPositionsAndSizes(){
    EToolkit::Position3i position(1, 2, 3);
    EToolkit::Size3i size(4, 5, 6);
    const EToolkit::Position3i& constPosition = position;
    const EToolkit::Size3i& constSize = size;

    ETOOLKIT_TEST_ASSERT("Position3 x", constPosition.getX() == 1);
    ETOOLKIT_TEST_ASSERT("Position3 y", constPosition.getY() == 2);
    ETOOLKIT_TEST_ASSERT("Position3 z", constPosition.getZ() == 3);
    ETOOLKIT_TEST_ASSERT("Size3 width", constSize.getWidth() == 4);
    ETOOLKIT_TEST_ASSERT("Size3 height", constSize.getHeight() == 5);
    ETOOLKIT_TEST_ASSERT("Size3 depth", constSize.getDepth() == 6);
    return true;
}

bool testBounds1(){
    EToolkit::Bounds1i bounds(10, 20);
    EToolkit::StaticArray<int, unsigned int, 2>& array = bounds;

    ETOOLKIT_TEST_ASSERT("Bounds1 x", bounds.getX() == 10);
    ETOOLKIT_TEST_ASSERT("Bounds1 width", bounds.getWidth() == 20);
    ETOOLKIT_TEST_ASSERT("Bounds1 array x", array[0] == 10);
    ETOOLKIT_TEST_ASSERT("Bounds1 array width", array[1] == 20);
    ETOOLKIT_TEST_ASSERT("Bounds1 x shares storage", &bounds.getX() == &array[0]);
    ETOOLKIT_TEST_ASSERT("Bounds1 width shares storage", &bounds.getWidth() == &array[1]);
    return true;
}

bool testBounds2(){
    EToolkit::Bounds2i bounds(1, 2, 3, 4);
    EToolkit::StaticArray<int, unsigned int, 4>& array = bounds;

    ETOOLKIT_TEST_ASSERT("Bounds2 x", bounds.getX() == 1);
    ETOOLKIT_TEST_ASSERT("Bounds2 y", bounds.getY() == 2);
    ETOOLKIT_TEST_ASSERT("Bounds2 width", bounds.getWidth() == 3);
    ETOOLKIT_TEST_ASSERT("Bounds2 height", bounds.getHeight() == 4);
    ETOOLKIT_TEST_ASSERT("Bounds2 array x", array[0] == 1);
    ETOOLKIT_TEST_ASSERT("Bounds2 array y", array[1] == 2);
    ETOOLKIT_TEST_ASSERT("Bounds2 array width", array[2] == 3);
    ETOOLKIT_TEST_ASSERT("Bounds2 array height", array[3] == 4);
    ETOOLKIT_TEST_ASSERT("Bounds2 x shares storage", &bounds.getX() == &array[0]);
    ETOOLKIT_TEST_ASSERT("Bounds2 height shares storage", &bounds.getHeight() == &array[3]);
    return true;
}

bool testBounds3(){
    EToolkit::Bounds3i bounds(1, 2, 3, 4, 5, 6);
    EToolkit::StaticArray<int, unsigned int, 6>& array = bounds;

    ETOOLKIT_TEST_ASSERT("Bounds3 x", bounds.getX() == 1);
    ETOOLKIT_TEST_ASSERT("Bounds3 y", bounds.getY() == 2);
    ETOOLKIT_TEST_ASSERT("Bounds3 z", bounds.getZ() == 3);
    ETOOLKIT_TEST_ASSERT("Bounds3 width", bounds.getWidth() == 4);
    ETOOLKIT_TEST_ASSERT("Bounds3 height", bounds.getHeight() == 5);
    ETOOLKIT_TEST_ASSERT("Bounds3 depth", bounds.getDepth() == 6);
    ETOOLKIT_TEST_ASSERT("Bounds3 array x", array[0] == 1);
    ETOOLKIT_TEST_ASSERT("Bounds3 array y", array[1] == 2);
    ETOOLKIT_TEST_ASSERT("Bounds3 array z", array[2] == 3);
    ETOOLKIT_TEST_ASSERT("Bounds3 array width", array[3] == 4);
    ETOOLKIT_TEST_ASSERT("Bounds3 array height", array[4] == 5);
    ETOOLKIT_TEST_ASSERT("Bounds3 array depth", array[5] == 6);
    ETOOLKIT_TEST_ASSERT("Bounds3 x shares storage", &bounds.getX() == &array[0]);
    ETOOLKIT_TEST_ASSERT("Bounds3 depth shares storage", &bounds.getDepth() == &array[5]);

    bounds.setY(20);
    bounds.setWidth(40);
    ETOOLKIT_TEST_ASSERT("Bounds3 setY updates storage", array[1] == 20);
    ETOOLKIT_TEST_ASSERT("Bounds3 setWidth updates storage", array[3] == 40);
    return true;
}

}

bool GeometryTest::run(){
    const EToolkitTest::TestCase tests[] = {
        {"Geometry positions and sizes", testPositionsAndSizes},
        {"Geometry Bounds1", testBounds1},
        {"Geometry Bounds2", testBounds2},
        {"Geometry Bounds3", testBounds3}
    };
    return EToolkitTest::runSuite("GeometryTest", tests);
}
