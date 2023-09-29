/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LaurieMoo;

/**
 *
 * @author Matthew Walker
 * Date: 1/30/2018
 * Description: LaurieMOO is a game that has players guess a randomly generated 
 * 4 digit integer  between 0000-9999. They will receive more or less 
 * "moo"'s based on correct numbers. They will receive more "MOO"'s if the 
 * numbers are in the correct place. The "MOO"'s and "moo"'s do not correspond 
 * to the specific number and it's position. 
 */

public class GuessRandomValue {
    
    // Constants
    private final int NUMBER_SIZE = 4; // expected size of the integer
    
    // Variables for GetRandomValue Class
    private final java.util.Random rndGenerator = new java.util.Random(); // random number generator 
    private final int[] answerArray = new int[NUMBER_SIZE]; // Store the randomly generated value in array
    
    /**
     * constructs a random value as an integer array
     */
    public GuessRandomValue(){
        answerArray[0] = rndGenerator.nextInt(10);
        answerArray[1] = rndGenerator.nextInt(10);
        answerArray[2] = rndGenerator.nextInt(10);
        answerArray[3] = rndGenerator.nextInt(10);
    }
    
    // Getters and setters
    
    /**
     * resets the answerArray values
     */
    public void setAnswer(){
        answerArray[0] = rndGenerator.nextInt(10);
        answerArray[1] = rndGenerator.nextInt(10);
        answerArray[2] = rndGenerator.nextInt(10);
        answerArray[3] = rndGenerator.nextInt(10);
    }
    
    /**
     * Sets the answer to a certain integer value that the method is passed
     * @param number
     * @parameters the intended answer integer 
     */
    public boolean setAnswer(int number){
        // Account for if the user inputs larger than a 4-digit int
        if (number < 0 || number > 9999){
            return true;
        }
    // sets random value to value in answerJTextField
    // using division and modular math
        answerArray[0] = number / 1000;
        number %= 1000;
        answerArray[1] = number / 100;
        number %= 100;
        answerArray[2] = number / 10;
        number %= 10;
        answerArray[3] = number;
        
        return true;
    }
    /**
     * gets the answer
     * @return 
     * @returns the answer as a string
     */
    public String getAnswer(){
        String returnString = "" + answerArray[0] + answerArray[1] + answerArray[2] + answerArray[3];
        return returnString;
    }
    /**
     * Counts the number of matches in the specific decimal places
     * @param number the intended answer integer
     * @return the number of matches between the guesses and the answer
     */
    public int getBigMooCount(int number){
        int count = 0; // intantiating count at 0
        String randValue = Integer.toString(number);
        // accounting for multiple leading 0's
        while(randValue.length() <4){
            randValue = "0" + randValue;
        }
    // Algorithm to determine the bigMooCount
    if(answerArray[0] == Integer.parseInt(Character.toString(randValue.charAt(0)))){
        count++;
    }
    if(answerArray[1] == Integer.parseInt(Character.toString(randValue.charAt(1)))){
        count++;
    }
    if(answerArray[2] == Integer.parseInt(Character.toString(randValue.charAt(2)))){
        count++;
    }
    if(answerArray[3] == Integer.parseInt(Character.toString(randValue.charAt(3)))){
        count++;
    }
    return count;
    }
    /**
     * counts the number of matches between the guess and any other decimal
     * places, excluding the ones that have already been counted
     * @param number the intended answer integer
     * @return
     */
    public int getLittleMooCount(int number){
        int count = 0;
        int bigMooCount = getBigMooCount(number);
        String randValue = Integer.toString(number);
        
        // Accounts for the loss of leading 0's when converted from string to int
        while(randValue.length() < 4){
            randValue = "0" + randValue;
        }
        
        //Copies the numerical guess for later reference
        int[] guessArray = new int [NUMBER_SIZE];
        guessArray[0] = Integer.parseInt(Character.toString(randValue.charAt(0)));
        guessArray[1] = Integer.parseInt(Character.toString(randValue.charAt(1)));
        guessArray[2] = Integer.parseInt(Character.toString(randValue.charAt(2)));
        guessArray[3] = Integer.parseInt(Character.toString(randValue.charAt(3)));
        
        // Array that keeps track of whether a number has been counted yet
        boolean[] guessBoolArray = new boolean [NUMBER_SIZE];
        boolean[] answerBoolArray = new boolean [NUMBER_SIZE];
        // Algorithm to count number of little moos
        for(int i = 0; i < NUMBER_SIZE; i++){
            for(int j = 0; j < NUMBER_SIZE; j++){
                if(answerArray[i]==guessArray[j] && guessBoolArray[j] == false && answerBoolArray[i] == false){
                    count++;
                    guessBoolArray[j] = true;
                    answerBoolArray[i] = true;
                }
            }
        }
        // Displays the variables to console window, in order to monitor the correct solution
        System.out.println(answerArray[0] + " " + answerArray[1] + " " + answerArray[2] + " " + answerArray[3]);
        System.out.println(guessArray[0] + " " + guessArray[1] + " " + guessArray[2] + " " + guessArray[3]);
        System.out.println("litte  " + "big");
        System.out.println(count + "      " + bigMooCount + "\n");
        
        // Makes sure that count does not include bigMoo's
        int returnValue = count-bigMooCount;
        if (returnValue >= 0){
            return returnValue;
        }
        return 0;
    }
    
    /**
     * Checks if guessed value is equal to answer
     * @param number the intended value integer
     * @return true or false
     */
    public boolean isCorrectGuess(int number){
        return getBigMooCount(number) == 4;
    }
}
