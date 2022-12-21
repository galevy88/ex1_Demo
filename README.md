
# Advenced_Exercises - UNIX only
This repo used for Advenced computing exercise 2
In this exercise we had to make KNN algorithm using cpp. KNN in a primitive ML algorithm that get as an input Data that seperate into 2 main parts: features and labels. Based on the features we want to make a prediction for a label for a new sample of data. The way KNN works is by calculating a distance function between the new sample to all the data in the training set. the label of the most fluent sampels with the smallest distance will be the prediction label of the new sample.

In this Excercise we have to make an implementation for 5 types of distances:
1. Euclidain Distance
2. Manheten Distance
3. Chebyshev Distance
4. Canberra Distance
5. Minkowski Distance

When you run the file you wil face an empty line for input there you will have the insert your vector input.
The insertation of the vector should be with spaces between the numbers like the following example:

![image](https://user-images.githubusercontent.com/91119719/207488828-9018edc3-73cb-4c85-8d2c-ea6d09c88ec0.png)

The code will compute the distances between the sample vector you inserted to all of the samples and will send you the following output:

![image](https://user-images.githubusercontent.com/91119719/207488348-f6a7379b-ee1b-4693-afdf-2311f77abe59.png)

The our that you will get is the class out by the KNN model

# IMPORTANT CLARIFICATION:
1. The size of iris vector must be 4, wine vectors must be 13 and beans vector must be 16
2. Each number within each vector must be seperated with spaces - Only 1 Space seperate between 2 numbers!
3. The run of the program should be from the main.cpp file
4. You can't end the input you insert with space or either start it with space
5. Every time you will insert vector and you will get result and after it you will have the option to insert new vector
6. You can stop this program by inset -1 as input


# COMPILING AND RUNNING COMMANDS:
In this repo there is a makefile for compiling the program. The instruction for run this program are:
1. run the command: <code>make</code> on your terminal
2. use ls to see that indeed a.out file was created
3. run <code>./a.out \<K> \<Data.csv> \<distance function> </code>
4. K = Notice K must be a number between 1 - 100 (Can be double but know that double double will be rounded - better to use int)
5. Data file must be only fro this group = {iris_classified.csv, wine_Classified.csv, beans_Classified.csv} - Other input will now accept
6. Distance function will be from the group = {AUC, MAN, CHB, CAN, MIN} - Other input will not accept
