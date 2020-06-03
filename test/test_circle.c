// test_circle - Tests for the functions in ../src/circle.c.

#include "../src/circle.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

// "Factory function" for easily constructing circles.
struct circle C(double x, double y, double radius)
{
    return (struct circle) {x, y, radius};
}

// Tests that tangent circles are not considered overlapped.
void test_tangent(void)
{
    assert(! overlapped_circles(C(0, 0, 2), C(4, 0, 2)));
}

// Tests that more distance circles are not considered overlapped.
void test_not_overlapped(void)
{
    assert(! overlapped_circles(C(0, 0, 2), C(5, 0, 2)));
    assert(! overlapped_circles(C(0, 0, 2), C(6, 0, 2)));
}

// Test that two different circles are considered overlapped.
void test_diff_overlapped(void)
{
    assert(overlapped_circles(C(1,2,3), C(0,0,3)));
}
void test_similar_overlapped(void)
{
    assert(overlapped_circles(C(10,2,5), C(10,2,5)));
}



// This defines `test_fn_t` to stand for the type of each test
// function above (no arguments and no result).
typedef void test_fn_t(void);

// Takes the name of a test and a pointer to the function to run
// the test. Runs the test and prints an informative message.
void run_test(const char* name, test_fn_t* fn)
{
    printf("%s%s%s", "test_", name, "... ");
    fflush(stdout);
    fn();
    printf("ok.\n");
}

// C Preprocessor macro to make it easier to call `run_test`.
#define RUN_TEST(N) run_test(#N, test_##N)


int main()
{
    RUN_TEST(tangent);
    RUN_TEST(not_overlapped);
    //
    // TODO: call your test functions here
    RUN_TEST(diff_overlapped);
    RUN_TEST(similar_overlapped);
    
}
