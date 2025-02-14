#include "raylib.h"

int main()
{
   
    
    Texture2D sprite;
    
    Sound sound;
    
    Music music;
    
    InitWindow(800, 450, "sprite");
    
    InitAudioDevice();
    
    SetTargetFPS(144);
    
    sprite = LoadTexture("billboard.png");
    sound = LoadSound("target.ogg");
    music = LoadMusicStream("country.mp3");
    
    
     float posX = -sprite.width;
    while (!WindowShouldClose())
    {
        
        UpdateMusicStream(music);
       
        
          posX += GetFrameTime() * 300;
         
         if (posX>800)
        {
            posX= -sprite.width;
           
            
        } 
        
        if (IsKeyPressed(KEY_SPACE))
        {
            StopMusicStream(music);
            PlayMusicStream(music);
        }
        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
        {
        Rectangle spriterect = {
            posX,
            100,
            sprite.width,
            sprite.height
        };
        
        
            if (CheckCollisionPointRec(GetMousePosition(), spriterect))
            {
            PlaySound(sound);
                
            }
            
        }
        
      
         BeginDrawing();
        ClearBackground(RAYWHITE);
       
           
            
        
            
            DrawTexture(sprite,posX, 100,  WHITE);

           EndDrawing();
        
        
    
    }
    StopMusicStream(music);
    
    CloseAudioDevice();
    CloseWindow();
}