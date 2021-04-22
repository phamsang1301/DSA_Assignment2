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

	switch (code) 
	{
		case 1:
		{
			int knightKey = (pEvent->nEventCode % 10000) / 10;
			int knightLevel = (pEvent->nEventCode % 10000) % 10;
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
		}

			break;
		case 3: 
			break;
		case -1:
			break;
		case 5: 
			break;
	}

		pEvent = pEvent->pNext;
	}
  
	return pTree;
}



//your code should be before that directive