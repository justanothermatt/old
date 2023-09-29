/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package twoellipseviewer;

import javax.swing.JFrame;

/**
 *
 * @author ID139
 */
public class TwoEllipseViewer {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        JFrame frame = new JFrame();
        frame.setSize(500,500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        TwoEllipseComponent component = new TwoEllipseComponent();
        frame.add(component);
        
        frame.setVisible(true);
    }
    
}
