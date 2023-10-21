package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

class Problem1Test {
    @Test
    void shouldReturnTrue_ifNumberContainsAInHexRepresentation() {
        int number = 10;
        assertTrue(Problem1.containsDigitAInHexadecimalRepresentation(number));
    }

    @Test
    void shouldReturnFalse_ifNumberDoesNotContainAInHexRepresentation() {
        int number = 9;
        assertFalse(Problem1.containsDigitAInHexadecimalRepresentation(number));
    }
}