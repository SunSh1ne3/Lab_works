package org.example;

import org.junit.Assert;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Problem2Test {
    @Test
    void segregateEvenAndOddNumbersTest1() {
        int Arr[]=Problem2.segregateEvenAndOddNumbers(new int[]{2, 1, 5, 8, 6});
        Assert.assertArrayEquals(new int[]{2, 8, 6, 1, 5}, Arr);
    }

    @Test
    void segregateEvenAndOddNumbersTest2() {
        int Arr[]=Problem2.segregateEvenAndOddNumbers(new int[]{1, 2, 3, 4, 5});
        Assert.assertArrayEquals(new int[]{2, 4, 1, 3, 5}, Arr);
    }

}