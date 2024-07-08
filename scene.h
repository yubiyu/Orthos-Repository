#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

struct Scene
{
    enum enumScene
    {
        SCENE_TITLE,
        SCENE_STAGE,
        SCENE_ARCHIVE,
        SCENE_SETTINGS
    };
    static int scene;

    enum enumInputContext
    {
        INPUT_CONTEXT_TITLE,
        INPUT_CONTEXT_STAGE,
        INPUT_CONTEXT_ARCHIVE,
        INPUT_CONTEXT_SETTINGS
    };
    static int inputContext;

    static void Initialize();
    static void ChangeScene(int whichScene);
    static void ChangeInputContext(int whichContext);
};


#endif // SCENE_H_INCLUDED
