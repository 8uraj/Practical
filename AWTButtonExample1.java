package com.example;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class AWTButtonExample1 {
   private JFrame mainFrame;
   private JButton button;
  
   public AWTButtonExample1(){
      prepareGUI();
   }
  
   public static void main(String[] args){
      AWTButtonExample1  awtButtonExample = new AWTButtonExample1();  
      awtButtonExample.showButtonDemo();
   }
  
   private void prepareGUI(){
      mainFrame = new JFrame("Java AWT Examples");
      mainFrame.setSize(400,400);
      mainFrame.setLayout(new FlowLayout());
      mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      
      button = new JButton("Click Me");
      button.addActionListener(new ButtonClickListener());
      mainFrame.add(button);
      mainFrame.setVisible(true);  
   }
  
   private class ButtonClickListener implements ActionListener{
      public void actionPerformed(ActionEvent e) {
         System.out.println("Button clicked.");
      }     
   }
  
   private void showButtonDemo(){
      mainFrame.setVisible(true);  
   }
}
