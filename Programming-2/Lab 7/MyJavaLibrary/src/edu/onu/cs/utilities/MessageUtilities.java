/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package edu.onu.cs.utilities;
import javax.swing.*;
/**
 *
 * @author Matt Walker
 */
public class MessageUtilities {
    
    private static int DEFAULT_DELAY = 1000;
    
    /**
     * DEFAULT_DELAYs the display of a message on the referenced label for the specified time.
     * @param widget    JLabel whose text is to be changed
     * @param message   String that is to be displayed
     * @param delay     The amount of time in milliseconds that is to elapse before displaying the message
     */
    public static void showDelayededMessage (JLabel widget, final String message, int delay){
        if (delay < 0) delay = DEFAULT_DELAY;
        Timer messagedelayTimer = new Timer ( delay, new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt){
                widget.setText(message);
            }
        });
        messagedelayTimer.setRepeats(false);
            messagedelayTimer.start();
    }
    /**
     * Changes the foreground color of the JComponent-derived widget after
     * the specified amount of time elapses
     * @param widget            An object from the JComponent-derived class whose foreground color is to be changed
     * @param color             The color that the foreground is to be changed to
     * @param delay             The amount of time in milliseconds to elapse before changing the foreground color
     */
    public static void setDelayedForeground(javax.swing.JComponent widget,
                                            final java.awt.Color    color,
                                            int                     delay){
    if (delay < 0) delay = DEFAULT_DELAY;
    Timer foregroundDelayTimer = new Timer( delay, new java.awt.event.ActionListener(){
        public void actionPerformed(java.awt.event.ActionEvent evt){
            widget.setForeground(color);
        }
    });
    foregroundDelayTimer.setRepeats(false);
    foregroundDelayTimer.start();
    }
}
