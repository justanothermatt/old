/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package twosquareviewer;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import javax.swing.JComponent;
/**
 *
 * @author ID139
 */
public class TwoSquareComponent extends JComponent {
    public void paintComponent(Graphics g){
        // Recover Graphics 2D
        Graphics2D g2 = (Graphics2D) g;
        
        // Construct and draw a rectangle
        Rectangle box1 = new Rectangle(105,155,20,20);
        g2.draw(box1);
        
        Rectangle box2 = new Rectangle(100,150,30,30);
        
        //Draw rectangles
        g2.draw(box1);
        g2.draw(box2);
    }
}
