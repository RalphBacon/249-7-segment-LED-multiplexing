# #249 7-segment LED multiplexing
#### Save GPIO pins by multiplexing your 7-segment displays

![Thumbnail-00002 (Phone)](https://user-images.githubusercontent.com/20911308/187711776-34264d4e-8e93-4b7c-aa4b-cfeed6a50af7.png)  
Link to video:  

[![JLCPCB-Purple](https://user-images.githubusercontent.com/20911308/159024530-3e083ca1-fea4-4ba9-97d3-a3af3fb979d2.png)](https://www.jlcpcb.com/cem)  

I'm using dual 7-segment LED displays in another project, but I figured I could have designed that using less GPIO pins than I did. So I tried out my theory here.  

Now, first things first. You would not usually drive the individual LED segments from an Arduino; it's too many GPIO pins. You would use some extra hardware to do that. But for this demo, we'll do it the easy way! 

However, to multiplex between the digits (watch the video to understand what that means) you would normally need one pin _**per digit**_.  

Not so here. I use a _**single GPIO pin**_ and a tiny dual Si4599 MOSFET chip that allows me to alternate between the digits just by bring the GPIO pin high and low. Easy peasy, lemon squeezy. I just love this little chip. A pity it's so hard to find these days (in 2022).  

Yes, you _could_ try using the Arduino's GPIO pin directly to source/sink the current but that would involve one Common Cathode and one Common Anode 7-degment digit. All a bit complex, to be honest. Not to mention that you can only source (or sink) ~20mA (40mA absolute max) per pin, so watch out!  

If you can't find the dual MOSFET you can either:

* use two discrete MOSFETs, one N-channel, one P-channel  
* use two NPN BJT transistors just to see how it all works (you'll need to use an extra CC pin on the Arduino for this)
* use one NPN and one PNP BJT transistor (sorry, no circuit diagram for this)
* use two GPIO pins on the Arduino to directly sink the current on the 7-segment digits (one pin per digit)

**Remember to use a current limiting resistor in all cases, about 220Ω will be fine**  

### HARDWARE
**Dual 7-segment** LED display, 0.28"  
![image](https://user-images.githubusercontent.com/20911308/188306973-531c16a6-07c6-435c-bad3-fcf3767b15f0.png)  
https://s.click.aliexpress.com/e/_DBvpDQL

**Si4599** Break Out Board (Bob), really expensive these days 🤨🤷  
![image](https://user-images.githubusercontent.com/20911308/188306930-4553f41a-194e-4698-b164-d11907cb8b5d.png)  
https://www.banggood.com/custlink/D3GCRqKQu9

**AO4606** Dual Mosfet drop-in equivalent to the Si4599, much cheaper too  
![image](https://user-images.githubusercontent.com/20911308/188307238-b8340feb-3f29-4676-beff-9b7ce1758b93.png)  
10PCS/LOT 4606 AO4606 MT4606 SOP-8 new and original  
https://s.click.aliexpress.com/e/_DkPliaP


---
### MORE  
Remember that circuit diagrams etc are right here in this GitHub!  

Useful or interesting video? You can support my channel:  
Buy Me A Coffee! https://www.buymeacoffee.com/ralphbacon  

► List of all my videos
(Special thanks to Michael Kurt Vogel for compiling this)  
http://bit.ly/YouTubeVideoList-RalphBacon

► If you like this video please give it a thumbs up, share it and if you're not already subscribed please consider doing so and joining me on my Arduinite (and other μControllers) journey

My channel, GitHub and blog are here:  
\------------------------------------------------------------------  
• https://www.youtube.com/RalphBacon  
• https://ralphbacon.blog  
• https://github.com/RalphBacon  
• https://buymeacoffee.com/ralphbacon  
\------------------------------------------------------------------
