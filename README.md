# #249 7-segment LED multiplexing
#### Save GPIO pins by multiplexing your 7-segment displays

![Thumbnail-00002 (Phone)](https://user-images.githubusercontent.com/20911308/187711776-34264d4e-8e93-4b7c-aa4b-cfeed6a50af7.png)  
Link to video:  

[![JLCPCB-Purple](https://user-images.githubusercontent.com/20911308/159024530-3e083ca1-fea4-4ba9-97d3-a3af3fb979d2.png)](https://www.jlcpcb.com/cem)  

I'm using dual 7-segment LED displays in another project, but I figured I could have designed that using less GPIO pins than I did. So I tried out my theory here.  

Now, first things first. You would not usually drive the individual LED segments from an Arduino; it's too many GPIO pins. You would use some extra hardware to do that. However, to multiplex between the digits you would normally need one pin per digit.  

Not so here. I use a single GPIO pin and a tiny dual Si4599 MOSFET chip that allows me to alternate between the digits just by bring the GPIO pin high and low. Easy peasy, lemon squeezy.  

Dual 7-segment LED display, 0.28"  
https://s.click.aliexpress.com/e/_DBvpDQL

