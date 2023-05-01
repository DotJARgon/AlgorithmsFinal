 /*
 * Authors: Tristan Brown, Marcelo Carpenter, Thomas Cho,
 *          Joshua Linnett, Aaron Mendoza, Harrison Williams
 * Assignment Title: Jigsaw Puzzles Epic
 * Assignment Description: This program allows users to solve a puzzle using
 *                         their own images.
 * Due Date: 5/2/2023
 * Date Created: 4/30/2023
 * Date Last Modified: 4/30/2023
 */

#ifndef FINALPROJECT_SOUNDHANDLER_H
#define FINALPROJECT_SOUNDHANDLER_H

#include <map>
#include <string>
#include "Sounds.h"
#include "SDL_Plotter.h"

using namespace std;

class SoundHandler {
private:
    map<Sounds, string> sounds;
    SDL_Plotter* plotter;
    bool special;
public:

    /*
     * description: sets all default values for the SoundHandler object
     * return: none
     * precondition: plotter parameter is valid
     * postcondition: all sounds are emplaced into the sounds map
     */
    SoundHandler(SDL_Plotter* plotter);

    /*
     * description: plays the sound passed as a parameter
     * return: void
     * precondition: sound is valid
     * postcondition: the appropriate sound is played
     */
    void playSound(Sounds sound);

    /*
     * description: plays 1 of 4 grab audios based on a randomly generated int
     * return: void
     * precondition: none
     * postcondition: 1 of the 4 grab audios is played
     */
    void playGrab();

    /*
     * description: plays 1 of the 3 default drop audios if the drop is not
     *              a special drop
     * return: void
     * precondition: none
     * postcondition: 1 of the 3 drop audios is played
     */
    void playDrop();

    /*
     * description: plays 1 of the 4 fail audios
     * return: none
     * precondition: none
     * postcondition: 1 of the 4 fail audios is played
     */
    void playFail();

    /*
     * description: plays 1 of the 4 right audios, determined by a random int
     * return: void
     * precondition: none
     * postcondition: plays 1 of the 4 right audios
     */
    void playRight();

    /*
     * description: plays 1 of the 2 click audios, determined by a random int
     * return: void
     * precondition: none
     * postcondition: plays 1 of the 2 click audios
     */
    void playClick();

    /*
     * description: plays the victory audio
     * return: none
     * precondition: none
     * postcondition: plays the victory audio
     */
    void playVictory();
    void playMusic();

};


#endif //FINALPROJECT_SOUNDHANDLER_H
