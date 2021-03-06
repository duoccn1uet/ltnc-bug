#include "CommonFunc.h"

mt19937 rd(chrono :: steady_clock :: now().time_since_epoch().count());

long long CommonFunc :: rand(long long Left, long long Right)
{
    return Left + rd() % (Right - Left + 1);
}

void CommonFunc :: show() {}
template <typename T, typename... V>
void CommonFunc :: show(T t, V... v)
{cerr << t; if (sizeof...(v)) cerr << ", "; show(v...);}

/**template <typename T, typename... V>
void CommonFunc :: show(T t, V... v)
{
    cerr << t; if (sizeof...(v)) cerr << ", "; show(v...);
}*/

bool SoundOn = true;

bool CommonFunc :: CheckCollision(const SDL_Rect& a, const SDL_Rect& b)
{
    if (a.x > b.x + b.w || b.x > a.x + a.w)
        return false;
    if (a.y > b.y + b.h || b.y > a.y + a.h)
        return false;
    return true;
}

int CommonFunc :: SqrDist(const SDL_Rect& a, const SDL_Rect& b)
{
    return (b.y-a.y)*(b.y-a.y) + (b.x-a.x)*(b.x-a.x);
}

bool CommonFunc :: LoadSound(Mix_Music*& sound, const string& path)
{
    if (sound != nullptr)
        Mix_FreeMusic(sound);
    sound = Mix_LoadMUS(path.c_str());
    if (sound == nullptr)
    {
        cout << "Failed to load beat music! SDL_mixer Error: " << Mix_GetError() << '\n';
        return false;
    }
    return true;
}

bool CommonFunc :: LoadSound(Mix_Chunk*& sound, const string& path)
{
    if (sound != nullptr)
        Mix_FreeChunk(sound);
    sound = Mix_LoadWAV(path.c_str());
    if (sound == nullptr)
    {
        cout << "Failed to load beat music! SDL_mixer Error: " << Mix_GetError() << '\n';
        return false;
    }
    return true;
}

void CommonFunc :: PlaySound(Mix_Music*& sound, int loop)
{
    if (SoundOn)
        Mix_PlayMusic(sound, loop);
}

void CommonFunc :: PlaySound(Mix_Chunk*& sound, int loop)
{
    if (SoundOn)
        Mix_PlayChannel(-1, sound, loop-1);
}
