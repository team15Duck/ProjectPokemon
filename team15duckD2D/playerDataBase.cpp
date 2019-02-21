#include "stdafx.h"
#include "playerDataBase.h"


playerDataBase::playerDataBase()
{
}


playerDataBase::~playerDataBase()
{
}

HRESULT playerDataBase::init()
{
	_currentPlayer = new player;
	_currentPlayer->init();
	_pokemon = nullptr;

	{
		pokemon* pm = new pokemon;
		pm->init(NULL, PM_BULBASAUR, 10, true);
		_currentPlayer->setPokemonArray(0, pm);
	}

	
	_currentPlayer->setCurrentPokemonCnt(1);


	return S_OK;
}

void playerDataBase::release()
{
	_currentPlayer->release();
	delete _currentPlayer;
	_currentPlayer = nullptr;
}

void playerDataBase::update()
{
}

void playerDataBase::render()
{
}

void playerDataBase::dataLoad(DATA data)
{
	bankPokemonLoad(data);
	currentPokemonLoad(data);
	fieldItemDataLoad(data);
	npcDataLoad(data);
	itemDataLoad(data);
	objectDataLoad(data);
	vector<string> vData = playerDataLoad(data);

	_currentPlayer->setName(vData[0]);
	_currentPlayer->setPlayTime(stoi(vData[1]));
	_currentPlayer->setTileX(stoi(vData[2]));
	_currentPlayer->setTileY(stoi(vData[3]));
	_currentPlayer->setSceneName(vData[4]);
	_currentPlayer->setMoney(stoi(vData[5]));
	_currentPlayer->setIsMan(stoi(vData[6]));
	_currentPlayer->setPos();
	_currentPlayer->setKey();
	_currentPlayer->aniSetUp();
	SCENEMANAGER->changeScene(_currentPlayer->getSceneName());
	UIMANAGER->uiDataSetting();
}

void playerDataBase::dataSave(DATA data)
{
	bankPokemonSave(data);
	currentPokemonSave(data);
	fieldItemDataSave(data);
	npcDataSave(data);
	itemDataSave(data);
	objectDataSave(data);
	playerDataSave(data);
}

void playerDataBase::bankPokemonLoad(DATA data)
{
}

void playerDataBase::currentPokemonLoad(DATA data)
{
	switch (data)
	{
		case playerDataBase::DATA_DEFAULT:
		break;
		case playerDataBase::DATA_1:case playerDataBase::DATA_2:case playerDataBase::DATA_3:case playerDataBase::DATA_4:case playerDataBase::DATA_5:case playerDataBase::DATA_6:


			HANDLE file;
			DWORD read;
			string fileName = "data/saveData" + to_string(data) + "/currentPokemon/num.txt";
			char str[1024];
			
			file = CreateFile(fileName.c_str(), GENERIC_READ, NULL, NULL,
				OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			
			ReadFile(file, str, 1024, &read, NULL);
			
			CloseHandle(file);

			string loadData;
			int i = 0;
			while (str[i] != '/')
			{
				loadData += str[i];
				i++;
			}
			

			for (int ii = 0; ii < stoi(loadData); ii++)
			{
				HANDLE file2;
				DWORD read2;
				string fileName2 = "data/saveData" + to_string(data) + "/currentPokemon/pokemon" + to_string(ii) + ".txt";
				pmPack* loadPokemon = new pmPack;
				
				file2 = CreateFile(fileName2.c_str(), GENERIC_READ, NULL, NULL,
					OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

				ReadFile(file2, loadPokemon, sizeof(pmPack), &read2, NULL);

				CloseHandle(file2);
				
				_currentPlayer->setPokemonArray(ii, new pokemon);
				_currentPlayer->getPokemonArray(ii)->init(0, (POKEMON)loadPokemon->index, loadPokemon->level, true);
				_currentPlayer->getPokemonArray(ii)->loadSavePack(loadPokemon);
			}


		break;
	}
}

void playerDataBase::fieldItemDataLoad(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::npcDataLoad(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::itemDataLoad(DATA data)
{
	


	switch (data)
	{
		case playerDataBase::DATA_DEFAULT:
		break;
		case playerDataBase::DATA_1:case playerDataBase::DATA_2:case playerDataBase::DATA_3:case playerDataBase::DATA_4:case playerDataBase::DATA_5:case playerDataBase::DATA_6:

			HANDLE file;
			DWORD read;
			string fileName = "data/saveData" + to_string(data) + "/itemData.txt";
			char str[1024];

			file = CreateFile(fileName.c_str(), GENERIC_READ, NULL, NULL,
				OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

			ReadFile(file, str, 1024, &read, NULL);

			CloseHandle(file);

			string loadData = str;

			for (int i = 0; i < loadData.size(); i++)
			{
				if (loadData[i] == '#') break;
				if (loadData[i] == '/')
				{
					string itemType;
					string num;
					int ii = i + 1;
					while (true)
					{
						if (loadData[ii] == ',') break;
						itemType += loadData[ii];
						ii++;
					}
					ii++;
					while (true)
					{
						if (loadData[ii] == '/' || loadData[ii] == '#') break;
						num += loadData[ii];
						ii++;
					}
					_currentPlayer->pushItem((ITEM_TYPE)stoi(itemType), stoi(num));
				}
			}

		break;
	}

}

void playerDataBase::objectDataLoad(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

vector<string> playerDataBase::playerDataLoad(DATA data)
{
	vector<string> vData;
	switch (data)
	{
		case playerDataBase::DATA_DEFAULT:
		break;
		case playerDataBase::DATA_1:case playerDataBase::DATA_2:case playerDataBase::DATA_3:case playerDataBase::DATA_4:case playerDataBase::DATA_5:case playerDataBase::DATA_6:
			HANDLE file;
			DWORD read;
			string fileName = "data/saveData" + to_string(data) + "/playerData.txt";
			char str[1024];

			file = CreateFile(fileName.c_str(), GENERIC_READ, NULL, NULL,
				OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

			ReadFile(file, str, 1024, &read, NULL);

			CloseHandle(file);

			string loadData = str;


		
			int i = 0;
			for (int ii = 0; ii < 7; ii++)
			{
				string pushData = "";
				
				while (loadData[i] != ',' && loadData[i] != '/')
				{
					pushData += loadData[i];
					i++;
				}
				vData.push_back(pushData);
				if (loadData[i] == ',')
				{
					i++;
					continue;
				}
				if (loadData[i] == '/')
				{
					break;
				}
			}

			
			
		break;
	}
	return vData;
}

void playerDataBase::bankPokemonSave(DATA data)
{
	switch (data)
	{
		case playerDataBase::DATA_DEFAULT:

		break;
		case playerDataBase::DATA_1:
		break;
		case playerDataBase::DATA_2:
		break;
		case playerDataBase::DATA_3:
		break;
		case playerDataBase::DATA_4:
		break;
		case playerDataBase::DATA_5:
		break;
		case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::currentPokemonSave(DATA data)
{
	switch (data)
	{
		case playerDataBase::DATA_DEFAULT:
		break;
		case playerDataBase::DATA_1:case playerDataBase::DATA_2:case playerDataBase::DATA_3:case playerDataBase::DATA_4:case playerDataBase::DATA_5:case playerDataBase::DATA_6:

			HANDLE file;
			DWORD write;
			string saveData = to_string(_currentPlayer->getCurrentPokemonCnt()) + "/";
			string fileName = "data/saveData" + to_string(data) + "/currentPokemon/num.txt";
			file = CreateFile(fileName.c_str(), GENERIC_WRITE, NULL, NULL,
				CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			WriteFile(file, saveData.c_str(), saveData.size() + 1, &write, NULL);
			CloseHandle(file);


			for (int i = 0; i < _currentPlayer->getCurrentPokemonCnt(); i++)
			{

				HANDLE file2;
				DWORD write2;
				
				

				string fileName2 = "data/saveData" + to_string(data) + "/currentPokemon/pokemon" + to_string(i) + ".txt";
				file2 = CreateFile(fileName2.c_str(), GENERIC_WRITE, NULL, NULL,
					CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
				WriteFile(file, _currentPlayer->getPokemon()[i]->makeSavePack(), sizeof(pmPack), &write2, NULL);
				CloseHandle(file2);
			}


		break;
	}
}

void playerDataBase::fieldItemDataSave(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::npcDataSave(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::itemDataSave(DATA data)
{
	
	switch (data)
	{
		case playerDataBase::DATA_DEFAULT:
		break;
		case playerDataBase::DATA_1:case playerDataBase::DATA_2:case playerDataBase::DATA_3:case playerDataBase::DATA_4:case playerDataBase::DATA_5:case playerDataBase::DATA_6:


			HANDLE file;
			DWORD write;

			string saveData = "";
			if (_currentPlayer->getItem().size() != 0)
			{
				player::mapItemList map = _currentPlayer->getItem();
				for (player::mapItemIter iter = map.begin(); iter != map.end(); iter++)
				{
					saveData += "/";
					saveData += to_string(iter->first);
					saveData += ",";
					saveData += to_string(iter->second);
				}
				saveData += "#";
				

			}
			string fileName = "data/saveData" + to_string(data) + "/itemData.txt";
			file = CreateFile(fileName.c_str(), GENERIC_WRITE, NULL, NULL,
				CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

			WriteFile(file, saveData.c_str(), saveData.size() + 1, &write, NULL);

			CloseHandle(file);

		break;
	}
}

void playerDataBase::objectDataSave(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::playerDataSave(DATA data)
{
	switch (data)
	{
		case playerDataBase::DATA_DEFAULT:
		break;
		case playerDataBase::DATA_1:case playerDataBase::DATA_2:case playerDataBase::DATA_3:case playerDataBase::DATA_4:case playerDataBase::DATA_5:case playerDataBase::DATA_6:


			HANDLE file;
			DWORD write;

			string saveData;

			saveData = _currentPlayer->getName() + "," + to_string((int)_currentPlayer->getPlayTime()) + ","
						+ to_string(_currentPlayer->getTileX()) + "," + to_string(_currentPlayer->getTileY()) + ","
						+ _currentPlayer->getSceneName() + "," + to_string(_currentPlayer->getMoney()) + "," + to_string(_currentPlayer->getIsMan()) +"/";

			string fileName = "data/saveData" + to_string(data) + "/playerData.txt";

			file = CreateFile(fileName.c_str(), GENERIC_WRITE, NULL, NULL,
				CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

			WriteFile(file, saveData.c_str(), saveData.size() + 1, &write, NULL);

			CloseHandle(file);

		break;
	}


}
