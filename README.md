# MakeUofT

# Pandora’s Box
Presented by Jacqueline Zhou, Katherine Fouriner, Valentina Lin, Yiling Fan

## Inspiration
Our team was inspired to create an unpractical interactive and entertaining experience that embraces nonsensical challenges by forcing the user to think outside the box. We were inspired by the joy that comes from tackling absurd challenges to gain the satisfaction of success. 

## What it does
The puzzle box has a combination of four puzzles that need to be completed in the correct order for the player to succeed. The first test is a touch and light test where the user needs to touch the sensor while “turning off the light.” The next test requires the user to rub their hands to generate friction and increase their body temperature. The third test allows the user to release their internal frustrations by screaming and triggering the sound sensor to pass. In the fourth challenge, the player needs to press three switches at the same time to unlock a riddle on the screen. After solving the riddle on the screen, the user is successful! 

## How we built it
The first step in the project involved visualizing the box and the various challenges. The logic and challenges for the puzzle box were built using Arduinos and various sensors (light, touch, temperature, sound, and switches) to get user input. We first tested each sensor for regular inputs and then set a threshold (ex. minimum sound level) to make the challenges more difficult for the user. The physical box was modeled in AutoDesk Fusion 360 that was then 3D printed. 

## Challenges we ran into
Our team, consisting of beginner hackers and first-year engineering students, faced technical challenges, notably with our sound sensor that consistently output maximum values due to excessive sensitivity. Through testing, we delved into understanding the units of the sensor's output, exploring factors such as amplitude and frequency of sound waves, where we eventually discovered that the sensor provided arbitrary numerical values. Despite these obstacles, we persevered and successfully fine-tuned the sensor to be less reactive to ambient noise. This adjustment ensures a more accurate representation of sound levels, especially in mitigating the impact of sudden loud noises. 

## Accomplishments that we're proud of
As most of our team had no prior experience with hardware, we are proud of learning a variety of skills and of designing and building a project from scratch within 24 hours.

## What we learned
Throughout the process, our team learned how to use a variety of Arduino sensors. Apart from learning about the outputs of each individual sensor, our team learned about connecting multiple sensors together on the board. We also learned about CAD by creating the various 3D printed parts. 

## What's next for Pandora’s Box
Looking forward, we hope to add more interactive and challenging components such as using a camera to implement a facial recognition feature that detects emotions so the player can only win if they are happy. 
