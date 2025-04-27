                                                                
                                                                
                                                                
         ..:::..            .:::..            ..::..            
       :@@@@@@@@@@.      .@@@@@@@@@#.      -@@@@@@@@@@.         
      +@@@@@%%@@@@@:    =@@@@@%%@@@@@:    #@@@@@@@@@@@@*        
     :@@@@:    *@@@@.  :@@@@+    #@@@@.  +@@@@.    =@@@@+       
     #@@@@     :@@@@=  #@@@@     .@@@@-  *@@@@.    .@@@@*       
     %@@@#     .@@@@* .@@@@*      @@@@@.           -@@@@+       
     @@@@#     .@@@@% .@@@@=      %@@@@.         .#@@@@%.       
     @@@@#     .@@@@% .@@@@=      %@@@@.       .%@@@@@=.        
     %@@@#     .@@@@* .@@@@*      @@@@@.    .+@@@@@@=.          
     #@@@@     :@@@@= .#@@@@      @@@@-    =@@@@@*.             
     -@@@@:   .*@@@@.  :@@@@=    #@@@@    #@@@@=                
      *@@@@@%%@@@@@:   .+@@@@@%%@@@@@:   *@@@@@@@@@@@@@@#       
       -@@@@@@@@@%.      :@@@@@@@@@%.    @@@@@@@@@@@@@@@#       
         ..:--:..          ..:--:..      ................       
                                                                

newcostfunc.cpp has an extraneous value alpha. for now, this is deprecated.

cf2.cpp is the current canon file to be used.

if somehow cf2.cpp is giving you errors, this is probably because eigen-3.4.0 was imported incorrectly from github. specifically there's a file called "core" that should exist but doesn't. to fix this download eigen from the website again and replace the old one.

TL;DR -- cf2.cpp is the relevant file. if it doesn't work delete "eigen-3.4.0" and put in a new one downloaded directly from the eigen website