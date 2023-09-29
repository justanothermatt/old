/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package nameviewer;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import javax.swing.JComponent;

/**
 *
 * @author ID139
 */
public class NameComponent extends JComponent{
     public void paintComponent(Graphics g){
         
         Graphics2D g2 = (Graphics2D) g;
         
         // Drawing name
         g2.setColor(Color.RED);
         g2.drawString("Matt Walker", 200,400);
         
         // Drawing head
         g2.setColor(Color.BLUE);
         //          L    D            Center at 250,150
         g2.fillOval(200, 100, 50, 50);
         
         // Setting points
         Point2D rightHand = new Point2D.Double(275,175);
         Point2D leftHand = new Point2D.Double(175,175);
         Point2D beginBody = new Point2D.Double(225,150);
         Point2D endOfBody = new Point2D.Double(225,275);
         Point2D rightFoot = new Point2D.Double(275,325);
         Point2D leftFoot = new Point2D.Double(175,325);
         
         // Drawing lines
         Line2D body = new Line2D.Double(beginBody, endOfBody);
         Line2D arms = new Line2D.Double(leftHand, rightHand);
         Line2D rightF = new Line2D.Double(endOfBody, rightFoot);
         Line2D leftF = new Line2D.Double(endOfBody, leftFoot);
         
         g2.draw(body);
         g2.draw(arms); 
         g2.draw(rightF);
         g2.draw(leftF);
     }
}
