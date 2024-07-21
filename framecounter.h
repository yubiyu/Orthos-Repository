#ifndef FRAMECOUNTER_H_INCLUDED
#define FRAMECOUNTER_H_INCLUDED

class Framecounter
{
    int drawFrame, numFrames;
    int frameChangeCount, frameChangeDelay;

public:

    Framecounter();
    ~Framecounter();

    void Initialize(int num_frames, int frame_change_delay)
    {
        drawFrame = 0;
        numFrames = num_frames;

        frameChangeCount = 0;
        frameChangeDelay = frame_change_delay;
    }

    void Logic()
    {
        frameChangeCount ++;
        if(frameChangeCount >= frameChangeDelay)
        {
            frameChangeCount = 0;
            drawFrame ++;
        }
        if(drawFrame >= numFrames)
            drawFrame = 0;
    }

};

#endif // FRAMECOUNTER_H_INCLUDED
