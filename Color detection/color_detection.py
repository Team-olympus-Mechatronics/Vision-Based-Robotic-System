import cv2
import serial
import numpy as np 

image = cv2.imread("C:\\Users\\PC\\Desktop\\ROBOTICS CLUB\\2023_03_02_12_41_IMG_5927.jpg")

greyscale = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

show = cv2.imshow("image",greyscale)

k = cv2.waitKey(5) & 0xFF

if k == 27:
    break

cv2.destroyAllWindows()