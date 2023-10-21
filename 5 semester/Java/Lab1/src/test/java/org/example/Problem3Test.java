package org.example;

import org.junit.Assert;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Problem3Test {

    @Test
    void flattenMatrixTest1() {
        int Arr[]=Problem3.flattenMatrix(new int[][]{{1,2,3},{4,5,6},{7,8,9}});
        Assert.assertArrayEquals(new int[]{1, 4, 7, 2, 5, 8, 3, 6, 9}, Arr);
    }

    @Test
    void flattenMatrixTest2() {
        int Arr[]=Problem3.flattenMatrix(new int[][]{{3,2,1},{6,5,4},{9,8,7}});
        Assert.assertArrayEquals(new int[]{3, 6, 9, 2, 5, 8, 1, 4, 7}, Arr);
    }

}