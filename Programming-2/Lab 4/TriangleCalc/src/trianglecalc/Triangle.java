/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trianglecalc;

/**
 *
 * @author jacob
 */
public class Triangle {
    private double xA;
    private double xB;
    private double xC;
    private double yA;
    private double yB;
    private double yC;
    
    public Triangle(double x1, double y1 , double x2, double y2, double x3, double y3){
        xA = x1;
        xB = x2;
        xC = x3;
        yA = y1;
        yB = y2;
        yC = y3;
    }
    public double sideLength(double x1, double y1 , double x2, double y2){
        double length = Math.sqrt((x2 - x1)*(x2 - x1)+ (y2 - y1)*(y2 - y1));
        return length;
    }
    public double getSideAB(){
        return sideLength(xA,yA, xB, yB);
    }
    public double getSideAC(){ 
        return sideLength(xA, yA, xC, yC);
    }
    public double getSideBC(){
        return sideLength(xB,yB, xC, yC);
    }
    public double getPerimeter(double a, double b, double c){
        return a+b+c;
    }
    public double getArea(double a, double b, double c){
        double s = (a + b + c)/2;
        double area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
        
        return area;
    }
    public double getAngleC(double a, double b, double c){
         
        double angle = Math.acos((a*a + b*b - c*c)/(2*a*b));
        //double angle = (a*a + b*b - c*c)/(2*a*b);
        angle = Math.toDegrees(angle);
        return angle;
    }
    public double getAngleA(double a, double b, double c){
        
        double angle = Math.acos((b*b + c*c - a*a)/(2*b*c));
        //double angle = (b*b + c*c - a*a)/(2*b*c);
        angle = Math.toDegrees(angle);
        return angle;
    }
    public double getAngleB(double a, double b, double c){
        
        double angle = Math.acos((c*c + a*a - b*b)/(2*a*c));
        //double angle = (c*c + a*a - b*b)/(2*a*c);
        angle = Math.toDegrees(angle);
        return angle;
    }
}
