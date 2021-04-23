#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif


//your code should be after that directive


KnightTree*  siege(eventList* pEvent,ringsignList* pSarumanList)
{
	KnightTree* pTree = NULL; 
	//let's save the lady
	
	while(pEvent != NULL)
	{
		int code;
		if (pEvent->nEventCode == 5)
		{
			code = 5;
		}
		else if (pEvent->nEventCode < 0)
		{
			code = -1;
		}
		else if (pEvent->nEventCode >= 10000 && pEvent->nEventCode <= 19999) 
		{
			code = 1;
		}
		else  
		{
			code = pEvent->nEventCode / 1000;
		}
		int knightKey = (pEvent->nEventCode % 10000) / 10;
		int knightLevel = (pEvent->nEventCode % 10000) % 10;
	switch (code) 
	{
		case 1:
		{

			//add Knight into BST
			// while duplicate, increase knight's key
				// new kight's key must differ 777 888 999
				// if new kight's key is 998 but still duplicated, break.
		} 

			break;
		case 2:
		{
			int eventKey = pEvent->nEventCode % 1000;
			// Find knight who has knight's key nearest eventKey
			// min = |ABC - XYZ|
			// if more than 2 knight, chose the knight has smaller key.

			// increase chosen knight's level (max lvl = 9)

			// if knight's key = 777
				// turn tree into list NRL
				// buil tree with root = 777  
		}
			break;
		case 3: 
			break;
		case -1:
			{
				//if (tree != NULL)
					// find the kinght who has key nearest eventKey
					// if (knight's key = 777 && knight's lvl = monster's lvl)
						//pass
					// else if (monster's key = 777 && countLeaf = lvl's monster)
						// remove all kight that has the depth >= monster's lvl
					// else if momnster's key = 888
						// while monster's lvl > knight's lvl && tree != NULL
								// fight
					// else
						// if the knight's lvl >= monster's lvl 
							//knight wins
							//
						// else
							// knight loses
							// remove (kight)
								// (use in-order successor)
				
				
			}
			break;
		case 5: 
			break;
	}

		pEvent = pEvent->pNext;
	}
  
	return pTree;
}



//your code should be before that directive