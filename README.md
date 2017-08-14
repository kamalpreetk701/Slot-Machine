# Slot-Machine
-Slot machine using different geometric shapes, utilize the concept of inheritence and polymorphism.

The slot machine has three reels ,each with 4 symbols(rectangle,rhombus,issosceles triangle,right triangle) available in 25 different
symbols.Thus each reel can display total of 100 symbols.

Player starts with 10 free tokens.

To win the 3 times of his bet , he needs three shapes of same size.

To win two times of his bet,he needs three similar shapes of any size.

To win or loose nothing, he needs two similar shapes.

otherwise he loose the game(three different shapes).

Project consist of following files:-

1.Shape.h,Shape.cpp:-  abstract class working as an interface.

 * Also overloads the << operator to print the string representation of shape object.
 
2.Rectangle.h,Rectangle.cpp,Isosceles.h,Isosceles.cpp,RightTriangle.h,RightTriangle.cpp,Rhombus.h,Rhombus.cpp:-all inherit the Shape class 
  and override all the virtual functions in shape class.
  
 * Provide the draw() function which returns the 2d vector grid and takes the arguments penchar(char which will draw shape) and fill char
  which will fill the empty shape.
 * Provide the draw_on_screen() function which prints the 2d vector returned by draw() on the screen.
 * Also provide the function toString(), which returns the string representation of a geometric shape like generic name,static    
   type,dynamic type,description,id,bouding box width,bounding box height,screen area,geometric area,screen perimeter,geometric  
   perimeter.
  
3.Slot Machine.h,SlotMachine.cpp-This class maintains arrayy of three pointers each pointing to newly created shape object.

  *Runs the following algorith untill the user runs out of tokens:-
  
  1.Prompt for and read a bet.
  
  2.For each reel r,r-0,1,2
  
    2.1 let reel r point to newly created shape object of random type and random size.
    
  3.Display reel.
  
  4.Report outcome,payout,tokens left.
  
  5.Free dynamic memory consumed by reels.
  
  Step 2.1 expands to these steps:-
  
    a. Generate the random integer n,0<=n<=3.
    
    b. Generate a random width w, 1<=w<=25.
    
    c. If n=0, let the reel point to Rhombus object of width w.
    
    d. If n=1, let the reel point to Isosceles object of width w.
    
    e. If n=2, let the reel point to RightTriangle object of width w.
    
    f. If n=3,
    
             i. Generate random height h, 1<=h<=25.
             
             ii. let reel r point to a Rectangle of width w and height h.
             
    6. Souce.cpp
    
      Contains the main function to run slot machine also displays the string represenataion of the Rectangle.
             
             
    

