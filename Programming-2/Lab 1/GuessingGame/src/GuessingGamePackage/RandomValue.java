/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package GuessingGamePackage;

/**
 *
 * @author Matt Walker
 */
public class RandomValue {
    // code section 1 - instance variables
    private java.util.Random rndGenerator = new java.util.Random();
    private int randomValue;
    public final static int NUMBER_OF_VALUES = 100;
    
    // code section 2 - public contructor
    public RandomValue(){
        randomValue = rndGenerator.nextInt(NUMBER_OF_VALUES);
    }
    
    // code section 3 - getters and setters
    public void setRandomValue() {
        randomValue = rndGenerator.nextInt(NUMBER_OF_VALUES);
    }
    
    public void setRandomValue (int n) {
        if (n < 0 || n >= NUMBER_OF_VALUES)
            return;
        randomValue = n;
    }
    
    public int getRandomValue() {
        return randomValue;
    }
    
    // code section 4 - inquirers
    public boolean isCorrectValue (int value) {
        if (value == randomValue)
            return true;
        return false;
    }
    public int compareTo (int value) {
        return randomValue - value;
    }
}
