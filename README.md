# vehicle-side-mirrors-control

This project is used in car mirrors to automatically adjust the two sides mirror to help driver see the ground while reversing. 

When reverse signal is generated the two sides mirrors’ motors will turn in a direction for 3 seconds.

After the signal is removed, the two motors will go back to their previous position.

If the signal is interrupted at any time during the 3 seconds it will return automatically to its previous position.

It is simulated in Proteus simulator and programmed using Atmel studio.

the controller is ATTINY85 microcontroller.

![image](https://user-images.githubusercontent.com/119271600/221427621-be2355c1-2edb-4f58-9f6f-472422bed69a.png)

the code is based on timer interrupt which counts the 3 secondes and it starts counting just after reverse signal triggers.

![image](https://user-images.githubusercontent.com/119271600/221428006-4703710c-3ced-4dd2-9dce-0348250e39b6.png)
