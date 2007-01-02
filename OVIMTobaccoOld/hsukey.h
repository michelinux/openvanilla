#include <string>
#include <vector>

string KEY_B =	"\xe3\x84\x85";		//ㄅ
string KEY_I =	"\xe3\x84\x9e";		//ㄞ
string KEY_O =	"\xe3\x84\xa1";		//ㄡ
string KEY_P =	"\xe3\x84\x86";		//ㄆ
string KEY_T =	"\xe3\x84\x8a";		//ㄊ
string KEY_U =	"\xe3\x84\xa9";		//ㄩ
string KEY_W =	"\xe3\x84\xa0";		//ㄠ
string KEY_X =	"\xe3\x84\xa8";		//ㄨ
string KEY_Y =	"\xe3\x84\x9a";		//ㄚ
string KEY_Z =	"\xe3\x84\x97";		//ㄗ

string HSU_A_01	= "\xe3\x84\x9f";	//ㄟ
string HSU_A_02	= "\xe3\x84\x98";	//ㄘ
string HSU_C_03	= "\xe3\x84\x95";	//ㄕ
string HSU_C_04	= "\xe3\x84\x92";	//ㄒ
string HSU_D_05	= "\xcb\x8a";		//ˊ
string HSU_D_06	= "\xe3\x84\x89";	//ㄉ
string HSU_E_07	= "\xe3\x84\xa7";	//ㄧ
string HSU_E_08	= "\xe3\x84\x9d";	//ㄝ
string HSU_E_09	= "\xe3\x84\xa7";	//ㄧ
string HSU_F_10	= "\xcb\x87";		//ˇ
string HSU_F_11	= "\xe3\x84\x88";	//ㄈ
string HSU_G_12	= "\xe3\x84\x9c";	//ㄜ
string HSU_G_13	= "\xe3\x84\x8d";	//ㄍ
string HSU_H_14	= "\xe3\x84\x9b";	//ㄛ
string HSU_H_15	= "\xe3\x84\x8f";	//ㄏ
string HSU_J_16	= "\xcb\x8b";		//ˋ
string HSU_J_17	= "\xe3\x84\x93";	//ㄓ
string HSU_J_18	= "\xe3\x84\x90";	//ㄐ
string HSU_K_19	= "\xe3\x84\xa4";	//ㄤ
string HSU_K_20	= "\xe3\x84\x8e";	//ㄎ
string HSU_L_21	= "\xe3\x84\xa5";	//ㄥ
string HSU_L_22	= "\xe3\x84\xa6";	//ㄦ
string HSU_L_23	= "\xe3\x84\x8c";	//ㄌ
string HSU_M_24	= "\xe3\x84\xa2";	//ㄢ
string HSU_M_25	= "\xe3\x84\x87";	//ㄇ
string HSU_N_26	= "\xe3\x84\xa3";	//ㄣ
string HSU_N_27	= "\xe3\x84\x8b";	//ㄋ
string HSU_R_28	= "\xe3\x84\x9a";	//ㄚ
string HSU_R_29	= "\xe3\x84\x96";	//ㄖ
string HSU_S_30	= "\xcb\x99";		//˙
string HSU_S_31	= "\xe3\x84\x99";	//ㄙ
string HSU_V_32	= "\xe3\x84\x94";	//ㄔ
string HSU_V_33	= "\xe3\x84\x91";	//ㄑ
string HSU_G_34	= "\xe3\x84\x8d";	//ㄍ
string HSU_E_35	= "\xe3\x84\xa7";	//ㄧ
string HSU_U_36	= "\xe3\x84\xa9";	//ㄩ
string HSU_J_37	= "\xe3\x84\x90";	//ㄐ

const static char tones[] ="dfjs";

bool hsuKeyToBpmf (const char* keyStr, string& bpmfStr) {
	const static unsigned int
		isUnique[] = {
			0, 1, 0, 0, 0, 0, 0,
			0, 1, 0, 0, 0, 0, 0,
			1, 1, 0, 0, 0, 1,
			1, 0, 1, 1, 1, 1};

	vector<string> bpmfVec;
	size_t length = bpmfStr.length();
	if(length >= 2)
		bpmfVec.push_back(" ");
	if(length >= 4)
		bpmfVec.push_back(" ");
	if(length >= 7)
		bpmfVec.push_back(" ");
	if(length >= 10)
		bpmfVec.push_back(" ");
	if(length > 12)
		return false;

	for (size_t i = 0; i < strlen(keyStr); i++) {
		char key = keyStr[i], keyNext;
		if(i < strlen(keyStr) - 1) keyNext = keyStr[i+1];
		else keyNext = 0;
		//if ( (pb[phi] =one2one[ch -'a']) == 0 )
		if (!isUnique[key - 'a']) {
			bool isNotIyNext = (keyNext != 'e' && keyNext != 'u');
			bool isToneNext = false;			
			for (int j = 0; j < 4; j++) {
				if (tones[j] == keyNext || !keyNext) {
					isToneNext = true;
					break;
				}
			}

			switch (key) {
				case 'a':
					bpmfVec[i] = (i > 0)? HSU_A_01: HSU_A_02;
					break;
				case 'c':
					bpmfVec[i] = isNotIyNext? HSU_C_03: HSU_C_04;
					break;
				case 'd':
					bpmfVec[i] = (i > 0)? HSU_D_05: HSU_D_06;
					break;
				case 'e':
					bpmfVec[i] =
						(i == 0)? HSU_E_07:
							((key = keyStr[i-1], key == 'e' || key == 'u')? HSU_E_08: HSU_E_09);
					break;
				case 'f':
					bpmfVec[i] = (i > 0)? HSU_F_10: HSU_F_11;
					break;
				case 'g':
					bpmfVec[i] = (i > 0 || isToneNext)? HSU_G_12: HSU_G_13;
					break;
				case 'h':
					bpmfVec[i] = (i > 0 || isToneNext)? HSU_H_14: HSU_H_15;
					break;
				case 'j':
					bpmfVec[i] =
						(i > 0)? HSU_J_16:
							(isNotIyNext? HSU_J_17: HSU_J_18);
					break;
				case 'k':
					bpmfVec[i] = (i > 0 || isToneNext)? HSU_K_19: HSU_K_20;
					break;
				case 'l':
					bpmfVec[i] =
						(i > 0)? HSU_L_21:
							(isToneNext? HSU_L_22: HSU_L_23);
					break;
				case 'm':
					bpmfVec[i] = (i > 0 || isToneNext || !keyNext)? HSU_M_24: HSU_M_25;
					break;
				case 'n':
					bpmfVec[i] = (i > 0 || isToneNext)? HSU_N_26: HSU_N_27;
					break;
				case 'r':
					bpmfVec[i] = (i > 0)? HSU_R_28: HSU_R_29;
					break;
				case 's':
					bpmfVec[i] = (i > 0)? HSU_S_30: HSU_S_31;
					break;
				case 'v':
					bpmfVec[i] = isNotIyNext? HSU_V_32: HSU_V_33;
					break;
				default:
                    return false;
			} //end of switch()
		} //end of if()
		else {
			switch (key) {
				case 'b':
					bpmfVec[i] = KEY_B;
					break;
				case 'i':
					bpmfVec[i] = KEY_I;
					break;
				case 'o':
					bpmfVec[i] = KEY_O;
					break;
				case 'p':
					bpmfVec[i] = KEY_P;
					break;
				case 't':
					bpmfVec[i] = KEY_T;
					break;
				case 'u':
					bpmfVec[i] = KEY_U;
					break;
				case 'w':
					bpmfVec[i] = KEY_W;
					break;
				case 'x':
					bpmfVec[i] = KEY_X;
					break;
				case 'y':
					bpmfVec[i] = KEY_Y;
					break;
				case 'z':
					bpmfVec[i] = KEY_Z;
					break;
				default:
					return false;
			}
		}
	} //end of for()


	if (bpmfVec.size() > 1 && bpmfVec[0].compare(HSU_G_34) == 0 &&
		(bpmfVec[1].compare(HSU_E_35) == 0 ||
		bpmfVec[1].compare(HSU_U_36) == 0))
          bpmfVec[0] = HSU_J_37;

	bpmfStr.clear();
	for(size_t idx = 0; idx < bpmfVec.size(); idx++)
		bpmfStr = bpmfStr.append(bpmfVec[idx]);

	return true;
}

/*
                     許氏鍵盤配置圖 
   
 ┌──┬──┬──┬──┬──┬──┬──┬──┬──┬──┐
 │    │  ㄠ│  ㄧ│  ㄖ│  ㄊ│  ㄚ│  ㄩ│  ㄞ│  ㄡ│  ㄆ│
 │Q   │W   │E ㄝ│R   │T   │Y   │U   │I   │O   │P   │
 └──┴──┴──┴──┴──┴──┴──┴──┴──┴──┘
   ┌──┬──┬──┬──┬──┬──┬──┬──┬──┐
   │  ㄘ│  ㄙ│  ㄉ│  ㄈ│  ㄍ│  ㄏ│ˋㄐ│  ㄎ│ㄦㄌ│
   │A ㄟ│S ˙│D ˊ│F ˇ│G ㄜ│H ㄛ│J ㄓ│K ㄤ│L ㄥ│
   └──┴──┴──┴──┴──┴──┴──┴──┴──┘  
     ┌──┬──┬──┬──┬──┬──┬──┐  
     │  ㄗ│  ㄨ│  ㄒ│  ㄑ│  ㄅ│  ㄋ│  ㄇ│  
     │Z   │X   │C ㄕ│V ㄔ│B   │N ㄣ│M ㄢ│  
     └──┴──┴──┴──┴──┴──┴──┘            
     ┌────────────────────┐            
     │              一    聲                  │            
     └────────────────────┘

┌─┬───────────────────────────┐
│字│     ㄅㄆㄇㄈㄉㄊㄋㄌㄍㄎㄏㄐㄒㄖㄗㄙㄝㄞㄟㄡㄣㄧ     │
│音│     ＢＰＭＦＤＴＮＬＧＫＨＪＣＲＺＳＥＩＡＯＮＥ     │
├─┼─────────┬─┬────┬─┬──────┬─┤
│字│ㄑㄚㄠㄢㄤㄥㄦㄨㄩ│對│ㄓㄔㄕㄘ│手│˙ˊˇㄜㄛˋ│標│
│形│ＶＹＷＭＫＬＬＸＵ│稱│ＪＶＣＡ│順│ＳＤＦＧＨＪ│點│
└─┴─────────┴─┴────┴─┴──────┴─┘

*/