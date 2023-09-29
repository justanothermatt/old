/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LaurieMooPackage;

/**
 *
 * @author harrison.heinig
 */
public class GuessRandomValue {
    //constants
    private final int ANSWER_SIZE = 4;      // Number of digits in number to be guessed
    
    //instance variables
    private java.util.Random rndGen = new java.util.Random();
    private int answer[] = new int[ANSWER_SIZE];        // Array that stores the values of number to be guessed
    private boolean checked[] = new boolean[ANSWER_SIZE];    // Array that determines whether a value has been checked
    
    //Constructors
    public GuessRandomValue() {
        answer[0] = rndGen.nextInt(10);     // Stores a random integer from 0 - 9
        answer[1] = rndGen.nextInt(10);     // Stores a random integer from 0 - 9
        answer[2] = rndGen.nextInt(10);     // Stores a random integer from 0 - 9
        answer[3] = rndGen.nextInt(10);     // Stores a random integer from 0 - 9
    }
    
    //Accessors and Mutators
    public void setAnswer() {
        answer[0] = rndGen.nextInt(10);     //Stores a random integer from 0 - 9
        answer[1] = rndGen.nextInt(10);     //Stores a random integer from 0 - 9
        answer[2] = rndGen.nextInt(10);     //Stores a random integer from 0 - 9
        answer[3] = rndGen.nextInt(10);     //Stores a random integer from 0 - 9
    }
    
    public void setAnswer(int num) {
        // Accounts for values more than 4 digits
        if (num > 9999)
            return;
        
        // Accounts for values less than 0e
        if (num < 0)
            return;
        
        // Stores text in answerTxtFld
        answer[0] = num / 1000;  // Stores the first int as the value in answer[0]
        num = num % 1000;        // Modifies number to remove already stored value
        answer[1] = num / 100;
        num = num % 100;
        answer[2] = num / 10;
        num = num % 10;
        answer[3] = num;      
    }
   
    //getAnswer
    public String getAnswer () {
        String answerStr = "" + answer[0] + answer[1] +answer[2] +answer[3];
        return answerStr;
    }
    
    //getBigMooCount
    public int getBigMooCount (int number) {
        int bigCount = 0;                               // Number of Big Moos
        String rndValue = Integer.toString(number);     // Converts number to a string
        
        // Adds a leading zero if rndValue is less than 4 digits
        while (rndValue.length() < 4)
            rndValue = "0" + rndValue;
        
        // Increases big count if a number in the value guessed is in the correct location
        if (answer[0] == Integer.parseInt(Character.toString(rndValue.charAt(0)))) {
            bigCount++;
            checked[0] = true;       // Sets checked to true indicating this location has been tested
        }
        else {
            checked[0] = false;  // Sets checked to false indicating this location has not been tested
        }
        
       
        if (answer[1] == Integer.parseInt(Character.toString(rndValue.charAt(1)))){
            bigCount++;
            checked[1] = true;      // Sets checked to true indicating this location has been tested
        }
        else {
            checked[1] = false;     // Sets checked to false indicating this location has not been tested
        }
        
        if (answer[2] == Integer.parseInt(Character.toString(rndValue.charAt(2)))) {
            bigCount++;
            checked[2] = true;      // sets checked to true indicating this location has been tested
        }
        else {
            checked[2] = false;     // Sets checked to false indicating this location has not been tested
        }
        
        if (answer[3] == Integer.parseInt(Character.toString(rndValue.charAt(3)))) {
            bigCount++;
            checked[3] = true;      // Sets checked to true indicating this location has been tested
        }
        else {
            checked[3] = false;     // Sets checked to false indicating this location has not been tested
        }
        
        return bigCount;
    }
    
    //getLittleMooCount
    public int getLittleMooCount (int number) {
        int littleCount = 0;                             // Number of Little Moos
        int bigCount = getBigMooCount(number);           // Number of Big Moos
        String rndValue = Integer.toString(number);      // Converts number to a string
        
        //Adds a leading zero if rndValue is less than 4 digits
        while (rndValue.length() < 4)
            rndValue = "0" + rndValue;
        
        // Copies guess as an int
        int guess[] = new int [ANSWER_SIZE];
        
        int value = Integer.parseInt(rndValue);
        
        guess[0] = value / 1000;
        value = value % 1000;
        guess[1] = value / 100;
        value = value % 100;
        guess[2] = value / 10;
        value = value % 10;
        guess[3] = value;
        
        // Count Little Moos
        for (int i = 0; i < ANSWER_SIZE; i++) {
            for (int j = 0; j < ANSWER_SIZE; j++) {
                if (checked[j] == false && guess[i] == answer[j]) {
                littleCount++;
                }
            }
        }
        System.out.println(answer[0] + "" + answer[1] + "" + answer[2] + "" + answer[3]);
        System.out.println( guess[0] + "" +  guess[1] + "" +  guess[2] + "" +  guess[3]);
        System.out.println(bigCount + "\n" + littleCount + "\n");
        
        int returnVl = littleCount;
        
        //Ensures that Big Moos are not counted twice
        if (littleCount + bigCount > 4) {
            returnVl = littleCount - bigCount;
        }
        
            
        // Ensures that there are never more than 4 little moos
        if (returnVl >= ANSWER_SIZE)
            return ANSWER_SIZE;
        // Returns Little Moos unless there are none
        if (returnVl >= 0)
            return returnVl;
        return 0;
    }
    
    
    //isCorrectGuess
    public boolean isCorrectGuess(int number) {
        if (getBigMooCount(number) == 4)
            return true;
        return false;
    }
}
