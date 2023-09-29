/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tictactoe;

/**
 * This class is designed to edit the values of a tic-tac-toe Board
 * @author Matt Walker
 */
public class Board {
    private final int ARRAY_SIZE = 9;
    
    //Value for an empty cell
    public static final char BLANK = ' ';   // Blank variable which fills the button with nothing
    
    //Value for an O cell
    public static final char CIRCLE = 'O';  // O variable that fills the button with an O
    
    //Value for an X cell
    public static final char CROSS = 'X';   // X variable that fills the button with an X
    
    char[] gameBoard;   //Character array that stores Board marks
    
    //Creating a new Board with blank values
    public Board(){
        gameBoard = new char[ARRAY_SIZE];
    }
    
    /**
     * Tests for if the player is playing on a position that has been played 
     * already. Data input is not vetted
     * @param location - Location of the cell being chosen
     * @return - true if they can play there, otherwise false
     */
    public boolean isLegalMove(int location){
        if(gameBoard[location] == CIRCLE || gameBoard[location] == CROSS){
            return false;           
        }
        return true;
    }
    
    /**
     * Makes sure the move is legal, then marks it with the correct input
     * @param location - Location of the cell being chosen
     * @param mark - The mark of the player (i.e CROSS or CIRCLE)
     * @return - true if cell is changed, false otherwise
     */
    public boolean placeMarkAt(int location, char mark){
        if(isLegalMove(location)){
            gameBoard[location] = mark;
            return true;
        }
        return false;
    }
    
    /**
     * Tells the code what the value of a given cell is
     * @param location - Location of the cell being chosen
     * @return - value of the cell chosen
     */
    public char getMarkAt(int location){
        return gameBoard[location];
    }
    
    public boolean hasThreeInRow(char mark){
        
        //Checking rows
        if(gameBoard[0] == mark && gameBoard[1] == mark && gameBoard[2] == mark){
            return true;
        }
        else if(gameBoard[3] == mark && gameBoard[4] == mark && gameBoard[5] == mark){
            return true;
        }
        else if(gameBoard[6] == mark && gameBoard[7] == mark && gameBoard[8] == mark){
            return true;
        }
        
        //Checking columns
        else if(gameBoard[0] == mark && gameBoard[3] == mark && gameBoard[6] == mark){
            return true;
        }
        else if(gameBoard[1] == mark && gameBoard[4] == mark && gameBoard[7] == mark){
            return true;
        }
        else if(gameBoard[2] == mark && gameBoard[5] == mark && gameBoard[8] == mark){
            return true;
        }
        
        //Checking diagonals
        else if(gameBoard[0] == mark && gameBoard[4] == mark && gameBoard[8] == mark){
            return true;
        }
        else if(gameBoard[2] == mark && gameBoard[4] == mark && gameBoard[6] == mark){
            return true;
        }
        
        return false;   //Default return
    }
    
    /**
     * resets the Board to all blank cells
     */
    public void resetBoard(){
        for(int i = 0; i < ARRAY_SIZE; i++){
            gameBoard[i] = BLANK;
        }
    }
}
