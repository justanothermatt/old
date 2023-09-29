/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pigs;

/**
 * The Player class is designed to be the main class for PigsGameJFrame. It's
 * purpose is to create methods that will be called on in game. These methods 
 * work together to let the player roll dice, keep their score, and play the game well.
 * @author Matt Walker
 */
public class Player {
    
    int dieOne    = 0;  // stores value of dice 1
    int dieTwo    = 0;  // stores value of dice 2
    int turnScore = 0;  // keeps track of the turn score for the individual player
    int gameScore = 0;  // keeps track of the game score for the individual player
    
    /**
     * The rollDie method will perform the rolling of the individual die being 
     * displayed on each of the two dice objects; the returned values are
     * to be used to update the game and turn scores, as well as the status conditions for.
     * @param die1
     * @param die2
     * @return the integer value of the combined two rolled dice
     */
    public int rollDie( dice die1, dice die2 ) {
        dieOne       = die1.rollDie();
        dieTwo       = die2.rollDie();
        int diceRoll = dieOne + dieTwo;
        turnScore = turnScore + diceRoll;
        
        //command line output for use of debugging
        System.out.println(dieOne + " " + dieTwo);
        return diceRoll;
    }
    
    /**
     * Check if wither die is valued at 1 and returns true and sets the turnScore
     * to 0.
     * @return a boolean expression that determines if the turnScore is lost
     */
    public boolean isTurnScoreLost(){
        if(dieOne == 1 || dieTwo == 1){
            turnScore = 0;
            return true;
        }
        else return false;
    }
    
    /**
     * This method checks for a 1 on both dice and returns true and resets the
     * players game score if true. 
     * @return a boolean value that relays whether the gameScore is lost
     */
    public boolean isGameScoreLost(){
        if(dieOne == 1 && dieTwo == 1){
            
            this.reset();
            return true;
        }
        else return false;
    }
    
    /**
     * This method is used to add the current player turn score to their game score
     * @return a boolean value on whether or not the addition was successful
     */
    public boolean addTurnScoreToGameScore(){
        int temp = gameScore;
        gameScore += turnScore;
        
        if(temp == gameScore) return false;
        else return true;
    }
    /**
     * This method is used to calculate whether or not the player has won the game
     * @return true if the player has scored at least 100 points, false otherwise
     */
    public boolean hasWon() {
        if(gameScore >= 100) return true;
        else return false;
    }
    /**
     * This method allows the turn score to be returned
     * @return the current turn score.
     */
    public int getTurnScore(){
        return turnScore;
    }
    /**
     * This method allows the game score to be returned
     * @return the current game score
     */
    public int getGameScore() {
        return gameScore;
    }
    
    /**
     * This method just resets the turn score and game score, usually 
     * to be used at the start of a new game
     */
    public void reset(){
        turnScore = 0;
        gameScore = 0;
    }
}
