#include "SDL_utils.h"

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT){
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Error: SDL failed to initialize\nSDL Error: '%s'\n", SDL_GetError());
        return ;
    }

    window = SDL_CreateWindow("Snake game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(!window){
        printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
        return ;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
        return ;
    }
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

bool menu(SDL_Renderer* renderer, TTF_Font* font, SDL_Surface* surface, SDL_Texture* texture, SDL_Event e){
    bool run=true;
    SDL_SetRenderDrawColor(renderer,196, 208, 163, 255 );
    SDL_RenderClear(renderer);
    
    SDL_Color color_text = { 255, 255, 255 };
    
    bool running=true;
    while(running){
        while(SDL_PollEvent(&e)){
            switch (e.type)
            {
            case SDL_QUIT:
                running=false;
                run=false;
                break;
            
            case SDL_KEYDOWN:
                if(e.key.keysym.sym==SDLK_SPACE) 
                {
                    running=false;
                    break;
                }
                if(e.key.keysym.sym==SDLK_ESCAPE){
                    running=false;
                    run = false;
                    break;
                }
            }
        }
        // clear the window 
		SDL_RenderClear(renderer);

		// text "Snake game"
        font=TTF_OpenFont("VeraMoBd.ttf",50);
        string text="Snake game";
        surface = TTF_RenderText_Solid(font, text.c_str(), color_text);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        SDL_Rect srcRest;
        SDL_Rect desRect;
        TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

        srcRest.x = 0;
        srcRest.y =  0;

        desRect.x = 110;
        desRect.y = 100;

        desRect.w = srcRest.w;
        desRect.h = srcRest.h;
		SDL_RenderCopy(renderer, texture, &srcRest, &desRect);
        //

        //text "Press space to play"
        font=TTF_OpenFont("VeraMoBd.ttf", 20);
        text="Press space to play";
        surface = TTF_RenderText_Solid(font, text.c_str(), color_text);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

        srcRest.x = 0;
        srcRest.y =  0;

        desRect.x = 150;
        desRect.y = 210;

        desRect.w = srcRest.w;
        desRect.h = srcRest.h;
		SDL_RenderCopy(renderer, texture, &srcRest, &desRect);
        //

        //text "Press escape to exit"
        font=TTF_OpenFont("VeraMoBd.ttf", 20);
        text="Press escape to exit";
        surface = TTF_RenderText_Solid(font, text.c_str(), color_text);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

        srcRest.x = 0;
        srcRest.y =  0;

        desRect.x = 145;
        desRect.y = 250;

        desRect.w = srcRest.w;
        desRect.h = srcRest.h;
		SDL_RenderCopy(renderer, texture, &srcRest, &desRect);
        //

		//draw to screen
		SDL_RenderPresent(renderer);

        
    }

    return run;
}

void SpeedUp(int score){
    if(score<=100) SDL_Delay(120);
    else if(score<=200) SDL_Delay(110);
    else SDL_Delay(100);
}

void GameOver(SDL_Renderer* renderer,SDL_Surface* surface, SDL_Texture* texture, TTF_Font* font, SDL_Event e, Mix_Chunk* chunk){//???
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255 );
    SDL_RenderClear(renderer);
    SDL_Color color_text={255, 255, 255};
    font=TTF_OpenFont("VeraMoBd.ttf",50);
    string text="Game Over!!!";
    surface = TTF_RenderText_Solid(font, text.c_str(), color_text);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_Rect srcRest;
    SDL_Rect desRect;
    TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

    srcRest.x = 0;
    srcRest.y =  0;

    desRect.x = 100;
    desRect.y = 150;

    desRect.w = srcRest.w;
    desRect.h = srcRest.h;
    bool running=true;
    chunk=Mix_LoadWAV("gameover.wav");
    Mix_PlayChannel(-1,chunk,0);
    while (running)
	{
		//event
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
				
				case SDL_QUIT:
				{
					running = false;
					break;
				}
			}
		}
		// clear the window to black
		SDL_RenderClear(renderer);
		
        //Copy a portion of the texture to the current rendering target.
		SDL_RenderCopy(renderer, texture, &srcRest, &desRect);

		SDL_RenderPresent(renderer);
	}
}

int Highscore(int score){
    ifstream input("Score.txt");
    if(!input.is_open()) return -1;
    int high_score;
    input>>high_score;
    if(score>high_score){
        ofstream output("Score.txt");
        high_score=score;
        output<<score;
        output.close();
    }
    input.close();
    return high_score;
}

void Quit(SDL_Window*& window,SDL_Renderer*& renderer){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();
}
