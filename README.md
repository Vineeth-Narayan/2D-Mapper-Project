// codeA.ino and codeA.py contain all the code needed for the project // 


// The remaining files are codes for subproject before the main project. //




2D-mapper

Team members
 -	Vineeth Narayan P
 -	Ankit
 -  Nakshatra 
 -  Anupama

Guides
- Rahul
- Gayatri


Objectives
To build a bot which autonomously travels around a given maze and gives the 2-dimensional map of the maze.
Which can be broken down as
- Detection of position of walls using ultra-sonic sensors.
- Movement of bot in the maze autonomously through decision-making code.
- Relaying position and plotting of 2-dimensional map by the bot.


Methodology
- The whole process is broken down to 5 different modules which are finally combined to get the 2d-mapper


	1)Using Ultrasonic sensors for relaying distances for walls from the bot
		Ultrasonic sensors have 4 pins being Vin, ground , trigger and echo pins.
		 Three ultrasonic sensors are attached infront , right and left side of the bot.
			Working:
				- When the vin pin and ground pin give the electrical voltage needed for the sensor.
				- When trigger pin is high it gives out ultrasonic waves which hit the nearest wall and get rebounded.
				- The echo pin receives the ultrasonic waves and the time duration between release
				 of the waves and detection of the waves in echo pin is used to find the distance.
				- Since the waves travel in speed of sound , distance is calculated from the wall as speed*time.

	2)Using L293D motor driver to drive and control the speed and direction of the bot
	 	The motor driver using half H bridge principle , controlling two motors at a time with
		  the ability to turn the motor in both clock-wise or anti clock-wise directions.
			Working:
				- L293D motor driver has 16 pins , 4 pins for 2 terminals of each of the motor (output).
				 4 pins from the arduino uno as input pins . 4 ground pins .
				2 pwm pins to control the speed . Voltage supply for motor pin and internal voltage supply pin.

				- When the voltage of one terminal pin is high and the other terminal is low ,
				 the motor drives in this voltage difference converting electrical to mechanical energy.
				  Hence on giving a high and low in the input pins results in a high and low output pins driving the motor,
				If voltage is high in the other terminal instead the motor would turn in opposite direction .
				 Hence direction of the motor can be controlled using the 
				motor driver.
				- The voltage difference between the terminals of the motor is directly propotional to the speed of the motor.
				Hence , the voltage supplied to the motors can be controlled using PWM pins.
				
				Therefore speed and direction of the bot can be controlled using the motor driver .

	3)Movement of the bot and autonomous decision making in time of obstacles.
		Since the bot moves autonomously , it should be able to make its own decisions on turning or moving forward based on the situation .
		Left-hand rule algorithm is implemented in the code of the bot for its decision making.
			Algorithm:

				STEP 1 - If distance of left wall is not in proximity (30cm) turn left.

                STEP 2 - If left wall exists (<30cm)  go straight.

				STEP 3 - If left wall exists and front wall exists at <30cm , turn right.                               

	4)Interfacing between arduino c program and python program to draw the 2d map
		- The position of the walls relayed to the arduino c porgram has to be interfaced to python for the plotting the 2d map.

		- Pyserial library is used to interface with the serial monitor os arduino.cc .

		- Coordinates of walls calculated are sent to the serial monitor which are read by python code using pyserial .

		- Matplotlib library is used to plot the 2d-map based on the coordinates received.
		 





Results

A 2D-mapper which detects its position based on its distances from the walls
 which is detected by ultrasonic sensors moves as per the left hand algorithm in the maze.
The decision making is done within the of arduino microcontroller.
The position of walls interfaced with using pyserial which builds the 2D-map using matplotlib 
using the co-ordinates received in the serial monitor.

Hence goals achieved

-Getting the bot to continuously relay distance values 
-Bot avoiding obstacles and making turns 
-Plotting the 2D map of the path it follows

Applications

-Applications in 
1. Maze solving
 The following other algorithms can be applied 
	Wall follower
	Pledge algorithm
	Trémaux's algorithm
	Dead-end filling
	Recursive algorithm
	Maze-routing algorithm
	Shortest path algorithm

	The optimizing of algorithm can make the maze solving much more efficient and quicker.

2. Shortest path finder bot 
	Bot which calculates different possibilities of solving the maze and comes up with the shortest path.

3.	Machine learning techniques implementation for developing a bot which can help in development of harder mazes or higher difficult mazes.


4.  Map plotting







#  References and acknowledgements 

- http://roboindia.com/tutorials/nodemcu-motor-driver-pwm/

- https://www.researchgate.net/publication/316664613_AUTONOMOUS_MAZE_SOLVING_ROBOT

- https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
