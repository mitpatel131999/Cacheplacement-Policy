

This Folder contain some of the code which i have write to get some 
initial output for one approch 

i have used direct Usimmm LLC level trace to simulate replaement policy

Aprox Beledy .cpp

this file contain and aproximate approch to get optimal cache lise ans victam

it is based on aproximateing distance(Delay) is number instructon between same memory access
using formulal

new_Expactes_Distance=(Alpha)(Actual_Distance_in_current_access) + (1-Alpha)(OLD_Expacted_Distance)


we have store the timestamp of laset access and Expacted Distance for each cacheline
we selects cache line which have Highest  Last_access TimeStamp + Expacted Distance as victam as per Beledy algorithm


we got aproximate 21% hit rate at value of Alpha= 0.39 
which was not very impressive.

i have implemened some other policy like LRU , MRU ,FIFO , RANDOM etc 
to compaire Reinforcement Learning based Policy to normal Hurestic based Policy

 

