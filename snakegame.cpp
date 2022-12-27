#include<iostream>
#include<graphics.h>
#include<time.h>
#include<stdio.h>


int main(){
//class A {

    int gd = DETECT,gm,key_dir,foodx, foody, snakex[200],snakey[200];
    initgraph(&gd,&gm,(char*)"");
     
     // initialization
//     int *length = new int; 
     int delaytime = 100;
        int *food = NULL;
        food = new int;
        *food = 28;
//     int food = 0;
     
     int body = 500;
     int p_dir = 1;
     int length = 1;
     int &r = length;            // Here we have used & operator to locate address of length
     bool game = true;
     
     
     for(int i=0; i< 200; i++){
     	snakex[i] = 0;
     	snakey[i] = 0;
	 }
	 
	 snakex[0] = 200, snakey [0] =200;
	 foodx = 200, foody = 200;
	 key_dir = 1;
//};	 
	 
	 //drawing game panel
	 
	 while(game){
	 	setfillstyle(SOLID_FILL, MAGENTA);
	 	bar(0,0,630,470);
	 	setfillstyle(SOLID_FILL,BLUE);
	 	bar(0,0,630,10);
	 	bar(0,0,10,470);
	 	bar(0,470,630,460);
	 	bar(620,10,630,470);
	 	
	 	 setfillstyle(SOLID_FILL,BLACK);
	 	 
	 	 if(snakex[0] == foodx && snakey[0] == foody){
	 	 	length = length + 1;
	 	 	food = food +1;
	 	 	delaytime = delaytime - 2;
			  
			  bar(foodx,foody,foodx + 10, foody + 10); 
			  
			  do{
			  	 foodx = (10 + rand() % 600);
			  	 foody = (10 + rand() % 450);
			  }
			  	while(getpixel(foodx,foody) != 0 && foodx > 10 && foody > 10);
			  	
			  	foodx = foodx / 10;
			  	foodx = foodx * 10;
			  	foody = foody / 10;
			  	foody = foody * 10;
			  	
			  	if(foodx == 10){
			  		foodx = rand() % 10 + 5;
			  		foodx = foodx * 10;
				  }
				  else if (foody == 10){
					foody = rand() % 10 + 5;
			  		foody = foody * 10;
					}
			  }
			    	bar(foodx, foody, foodx +10, foody +10);
			  
            setfillstyle(SOLID_FILL, YELLOW);
            
             if(GetAsyncKeyState(VK_RIGHT)){
            	key_dir = 1;
           	}else if(GetAsyncKeyState(VK_LEFT)){
           		key_dir = 2;
			}else if(GetAsyncKeyState(VK_UP)){
           		key_dir = 3;
			}else if(GetAsyncKeyState(VK_DOWN)){
           		key_dir = 4;
			}else{
				key_dir = 0;
			}
			
			switch(key_dir){
				case 0:
					if(p_dir == 1){
						snakex[0] = snakex[0] + 10;
					}else if(p_dir == 2){
						snakex[0] = snakex[0] - 10;
					}else if(p_dir == 3){
						snakey[0] = snakey[0] - 10;
					}else if(p_dir == 4){
						snakey[0] = snakey[0] + 10;
					}else{
					  key_dir = 0;	
					}
					break;
				case 1 :
					snakex[0] = snakex[0] + 10;
					p_dir = 1;
					break; 
				case 2 :
					snakex[0] = snakex[0] - 10;
					p_dir = 2;
					break; 
				case 3 :
					snakey[0] = snakey[0] - 10;
					p_dir = 3;
					break; 	
				case 4 :
					snakex[0] = snakex[0] + 10;
					p_dir = 4;
					break; 	
			}
			
			// dispalying snake 
			for(int i =0; i< length; i++){
				bar(snakex[i], snakey[i], snakex [i] +10, snakey[i]+10);
				if(i%2==0){
					setfillstyle(SOLID_FILL, RED);
				}
				else{
					setfillstyle(SOLID_FILL, YELLOW);
				}
				
			}
			
			// body of snake
			 for(int i =199; i> 0; i--){
			 	snakex[i] = snakex[i-1];
			 	snakey[i] = snakey[i-1];
			 }
			  //bumping into body
			  
			  for(int i =2;i < r; i++){
			  	if(snakex[0]==snakex[i] && snakey[0] == snakey[i]){
			  		body = i;
			  		break;
				  }
			  }
			  
			  delay(delaytime);
			  if(snakex[0] >= 615 || snakex[0]<=5 || snakey[0] <= 5 || snakey[0]>=455){
			  	 std::cout<<"Snake Bumped into the wall !! \n";
			  	 game = false;
			  }
			  if(snakex[0] == snakex[body] && snakey[0] == snakey[body]){
			  	 std::cout<<"Snake Bumped into itself !! \n";
			  	 game = false;
			  }
			  
		  }
		
//		A a;
		std::cout<<"Your score is :"<<food -1<<"\n";
		std::cout<<"Game Over !!";
		getch();
		delete food;
		return 0;
	 }