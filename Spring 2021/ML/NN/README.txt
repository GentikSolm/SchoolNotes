NeuralGen.py
  - acts as a generator for neural networks. The program will iterate over 20k different combinations of parameters,
    and then save the best and worst 10, for each scaled and unscaled, to a txt file named Scores.txt
    When run, it will most likely output lots of warnings, most of which are related to poor fits,
    therefore these can be ignored. THE PROGRAM WILL TAKE A VERY LONG TIME TO RUN, THIS IS
    BECAUSE OF HOW MANY ITERATIONS IT IS DOING.

Results.py
  - This is a much faster script, built so that we can see the confusion matrices and
    scatter plot of the data without running NeuralGen. Once NeuralGen generates the
    scores file, you can take one of the lists and plug it into myList. MyList is then
    iterated over by the for loop, regenerating only the best fits, yeilding the
    confusion matrices. The titles of the confusion graphs are the decimal notation of
    the accuracy.
