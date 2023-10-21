package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

class Problem4Test {
    @Test
    void shouldReturnTrue_isGeometricProgression() {
        assertTrue(Problem4.isGeometricProgression("16,2,8,1,4"));
    }

    @Test
    void shouldReturnFalse_isGeometricProgression() {
        assertFalse(Problem4.isGeometricProgression("2,7,1"));
    }
}