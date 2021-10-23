# Use Guide

## Before use

Replicant Gadget only works on x64.

Extract Replicant Gadget wherever you want and run NierReplicantGadget.exe.

#### Hooking

Once you load the game the Gadget will automatically detect the game and attach to it.
All features will be disabled until Gadget attaches to the game (indicated at the top left by the Hooked text).

#### Supported Versions

`v1.0.0.0`
- ReplicantHook v1.0.0
    
`v1.0.3.0` (06/16/2021)
- ReplicantHook v2.0.0+

## Features

- `Player Status` - display player status (Health, level, Magic...)
- [`Teleport`](#teleport) - Teleport through the map
- `Inventory Management` - add/remove items
- `InfiniteHealth` - enables or disables infinite Health
- `InfiniteMagic` - enables or disables infinite Magic
- [`Model swapping`](#model-swapping) - set actor model (Kaine, Nier Father...)

### Teleport

This feature lets you set the playable actor position. 

`Store` button will save the current XYZ position.
`Restore` button will set the actor playable XYZ to the previously saved XYZ coordinates (if no XYZ where saved it will set it to (0,0,0)).

*Restrictions:*
  - Cannot teleport to an unloaded zone.


### Model Swapping

For the model swapping to work, after swapping the model with the tool, the user must trigger a loading zone.

*Restrictions:*
  - For model swapping to work game progress must pass a certain point (Ending A?).
 
*Available models:*
- `Kainé`
- `Nier Father`
- `Nier Young` - Act I
- `Nier Old` -  Act II
- `Nier Shadowlord`
