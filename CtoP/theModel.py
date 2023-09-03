import sys

#checking for correct number of arguments
if len(sys.argv) != 5:
    print("Incorrect number of arguments provided.")
    sys.exit(1)

#extracting arguments from command line
prompt = sys.argv[1]
action = sys.argv[2]
random = sys.argv[3]
path = sys.argv[4]

#use model to generate clip
if action == "Generate":
    #generate_without_input_audio(prompt, action, random)
    pass
elif action == "Replace":
    #generate_with_input_audio(prompt, action, random, path)
    pass
elif action == "Extend":
    #extend_segment(prompt, action, random, path, time)
    pass
elif action == "Infill":
    #infill_segment(prompt, action, random, path, ?)
    pass

#for now have pre-set clip
newTrackPath = "/Users/willsaliba/Desktop/80sBeat90bpm.wav"

#print result so c++ can capture it
print(newTrackPath)
