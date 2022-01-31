# Simplified-E-vahan

Abstract
   
       This project is the simulation of E-vahan portal.It would display the geolocation details given the license number.
       Hashing concept is implemented to achieve this.
       
Working
      
       The license number is the value to which the key is to be hashed.
       
       From 15-character license number only the last seven digits are taken to form the key.
       
       For those digits (last 7 digits) division remainder hash function is used to generate the key for the hash table.
       
       Separate chaining technique is used for collision handling.
