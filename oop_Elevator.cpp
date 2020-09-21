

/*Design an Elevator system */

/*
Basic features 

1. Process Car/Lift Calls
2. Process Hall Calls:
3. Move/Stop the Car
4. Indicating Moving Direction
5. Indicating Car Position
6. Open/Close the Doors
7. Trigger Emergency Brake


Classes and Objects 

1. Control objects
      a. ElevatorControl (handle all controls)
      b. Door (open/close)
      c. Car/Lift (speed, etc)
      d. Button (sbuclasses - HallCallButton, CarCallButton)
      e. Indicator (direction and floor number)
      f. Safety (overweight, etc)

2. Control Classes 
      a. DoorControl
      b. DriveControl (maintains motor)
      c. IndicatorControl 
            - CarPositionIndicator
            - CarDirectionIndicator
      d. ButtonControl
            - HallButtoncontrol
            - CarButtonControl


Sequence Flow 

1. Process hall calls 
      1.1 the elevator is moving towards the same direction as the passenger’s destination.
      1.2 the elevator is moving towards the opposite direction as the passenger’s destination.
*/