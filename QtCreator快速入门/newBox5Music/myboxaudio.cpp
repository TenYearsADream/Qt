/**********************版权声明****************************

所有源代码由www.yafeilinux.com原创，我们遵循Qt开源版的所有相关条款和协议。

您有权使用，传播和更改我们的代码，但请保证代码的开源。

以下源代码版权归www.yafeilinux.com所有，请不要用作商业用途。
**********************************************************/


#include "myboxaudio.h"
#include <QDebug>
qreal MyBoxAudio::boxVolume = 1.0;
MyBoxAudio::MyBoxAudio()
{

}
MyBoxAudio::MyBoxAudio(QString musicName)
{
    mediaObject = new Phonon::MediaObject();
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory);
    Phonon::createPath(mediaObject,audioOutput);
    mediaObject->setCurrentSource(Phonon::MediaSource(musicName));
}

void MyBoxAudio::play()
{
    audioOutput->setVolume(boxVolume);
    //每次播放前都先设置声音大小
    mediaObject->stop();
    mediaObject->play();
    //如果音乐已经执行过了一遍，需要先执行stop()函数，再执行play()函数，音乐才能再次播放。
}

