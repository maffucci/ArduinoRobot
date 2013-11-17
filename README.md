Robot Line Follow Config
========================

Example on-line has been wrongly inserted Robot.beginLCD().
The Robot class does not have a method beginLCD() but a method beginTFT().

On-line version: Robot.text("Done!",0,10, true);
The syntax of text is Robot.text (towrite, x, y, writeOrErase),
but writeOrErase, which assumes the value true or false is not accepted