package com.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class StudentGradeTest {

    @Test
    void testGradeA() {
        assertEquals("A", StudentGrade.getGrade(95));
    }

    @Test
    void testGradeB() {
        assertEquals("B", StudentGrade.getGrade(85));
    }

    @Test
    void testGradeC() {
        assertEquals("C", StudentGrade.getGrade(75));
    }

    @Test
    void testGradeD() {
        assertEquals("D", StudentGrade.getGrade(65));
    }

    @Test
    void testGradeE() {
        assertEquals("E", StudentGrade.getGrade(55));
    }

    @Test
    void testGradeF() {
        assertEquals("F", StudentGrade.getGrade(30));
    }

    @Test
    void testInvalid() {
        assertEquals("Invalid", StudentGrade.getGrade(101));
        assertEquals("Invalid", StudentGrade.getGrade(-5));
    }
}