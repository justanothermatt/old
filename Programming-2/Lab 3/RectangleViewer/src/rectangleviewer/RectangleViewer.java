/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rectangleviewer;

import javax.swing.JFrame;
import java.awt.Color;
/**
 *
 * @author Matt Walker
 */
public class RectangleViewer {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        JFrame frame = new JFrame();
        frame.setSize(300,400);
        Color myColor = new Color(128,255,128);
        frame.getContentPane().setBackground(myColor);
        frame.getContentPane().setForeground(Color.MAGENTA);
        frame.setTitle("Two rectangles");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        RectangleComponent component = new RectangleComponent();
        frame.add(component);
        
        frame.setVisible(true);
        
    }
    
}
