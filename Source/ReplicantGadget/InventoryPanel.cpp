#include "InventoryPanel.hpp"
wxBEGIN_EVENT_TABLE(InventoryPanel, wxPanel)
wxEND_EVENT_TABLE()

InventoryPanel::InventoryPanel(wxNotebook* parent, ReplicantHook* hook) : wxPanel(parent, wxID_ANY)
{
	this->hook = hook;

	_Recovery = new wxArrayString();
	_Cultivation = new wxArrayString();
	_Fishing = new wxArrayString();
	_Materials = new wxArrayString();
	_Key = new wxArrayString();

	// Recovery
	_Recovery->Add("Medicinal Herb");
	_Recovery->Add("Health Salve");
	_Recovery->Add("Recovery Potion");
	_Recovery->Add("Strength Drop");
	_Recovery->Add("Strength Capsule");
	_Recovery->Add("Magic Drop");
	_Recovery->Add("Magic Capsule");
	_Recovery->Add("Defense Drop");
	_Recovery->Add("Defense Capsule");
	_Recovery->Add("Spirit Drop");
	_Recovery->Add("Spirit Capsule");
	_Recovery->Add("Antidotal Weed");

	// Cultivation
	_Cultivation->Add("Speed Fertilizer");
	_Cultivation->Add("Flowering Fertilizer");
	_Cultivation->Add("Bounty Fertilizer");
	_Cultivation->Add("Pumpkin Seed");
	_Cultivation->Add("Watermelon Seed");
	_Cultivation->Add("Melon Seed");
	_Cultivation->Add("Gourd Seed");
	_Cultivation->Add("Tomato Seed");
	_Cultivation->Add("Eggplant Seed");
	_Cultivation->Add("Bell Pepper Seed");
	_Cultivation->Add("Been Seed");
	_Cultivation->Add("Wheat Seed");
	_Cultivation->Add("Rice Plant Seed");
	_Cultivation->Add("Dahlia Seed");
	_Cultivation->Add("Tulip Seed");
	_Cultivation->Add("Freesia Bulb");
	_Cultivation->Add("Red Moonflower Seed");
	_Cultivation->Add("Gold Moonlfower Seed");
	_Cultivation->Add("Peach Moonflower Seed");
	_Cultivation->Add("Pink Moonflower Seed");
	_Cultivation->Add("Blue Moonflower Seed");
	_Cultivation->Add("Indigo Moonflower Seed");
	_Cultivation->Add("White Moonflower Seed");
	_Cultivation->Add("Pumpkin");
	_Cultivation->Add("Watermelon");
	_Cultivation->Add("Melon");
	_Cultivation->Add("Gourd");
	_Cultivation->Add("Tomato");
	_Cultivation->Add("Eggplant");
	_Cultivation->Add("Bell Pepper");
	_Cultivation->Add("Beans");
	_Cultivation->Add("Wheat");
	_Cultivation->Add("Rice");
	_Cultivation->Add("Dahlia");
	_Cultivation->Add("Tulip");
	_Cultivation->Add("Freesia");
	_Cultivation->Add("Red Moonflower");
	_Cultivation->Add("Gold Moonlfower");
	_Cultivation->Add("Peach Moonflower");
	_Cultivation->Add("Pink Moonflower");
	_Cultivation->Add("Blue Moonflower");
	_Cultivation->Add("Indigo Moonflower");
	_Cultivation->Add("White Moonflower");

	// Fishing
	_Fishing->Add("Lugworm");
	_Fishing->Add("Earthworm");
	_Fishing->Add("Lure");
	_Fishing->Add("Sardine");
	_Fishing->Add("Carp");
	_Fishing->Add("Blowfish");
	_Fishing->Add("Bream");
	_Fishing->Add("Shark");
	_Fishing->Add("Blue Marlin");
	_Fishing->Add("Dunkleosteus");
	_Fishing->Add("Rainbow Trout");
	_Fishing->Add("Black Bass");
	_Fishing->Add("Giant Catfish");
	_Fishing->Add("Royal Fish");
	_Fishing->Add("Hyneria");
	_Fishing->Add("Sandfish");
	_Fishing->Add("Rhizodont");
	_Fishing->Add("Shaman Fish");

	// Materials
	_Materials->Add("Aquatic Plant");
	_Materials->Add("Deadwood");
	_Materials->Add("Rusty Bucket");
	_Materials->Add("Empty Can");
	_Materials->Add("Gold Ore");
	_Materials->Add("Silvert Ore");
	_Materials->Add("Copper Ore");
	_Materials->Add("Iron Ore");
	_Materials->Add("Crystal");
	_Materials->Add("Pyrite");
	_Materials->Add("Moldavite");
	_Materials->Add("Meteorite");
	_Materials->Add("Amber");
	_Materials->Add("Fluorite");
	_Materials->Add("Clay");
	_Materials->Add("Berries");
	_Materials->Add("Royal Fern");
	_Materials->Add("Tree Branch");
	_Materials->Add("Log");
	_Materials->Add("Natural Rubber");
	_Materials->Add("Ivy");
	_Materials->Add("Lichen");
	_Materials->Add("Mushroom");
	_Materials->Add("Sap");
	_Materials->Add("Mutton");
	_Materials->Add("Boar Meat");
	_Materials->Add("Wool");
	_Materials->Add("Boar Hide");
	_Materials->Add("Wolf Hide");
	_Materials->Add("Wolf Fang");
	_Materials->Add("Giant Spider Silk");
	_Materials->Add("Bat Fang");
	_Materials->Add("Bat Wing");
	_Materials->Add("Goat Meat");
	_Materials->Add("Goat Hide");
	_Materials->Add("Venison");
	_Materials->Add("Rainbow Spider Silk");
	_Materials->Add("Boar Liver");
	_Materials->Add("Scorpion Claw");
	_Materials->Add("Scorpion Tail");
	_Materials->Add("Dented Metal Board");
	_Materials->Add("Stripped Bolt ");
	_Materials->Add("Broken Lens");
	_Materials->Add("Severed Cable");
	_Materials->Add("Broken Arm");
	_Materials->Add("Broken Antena");
	_Materials->Add("Broken Motor");
	_Materials->Add("Broken Battery");
	_Materials->Add("Mysterious Switch");
	_Materials->Add("Large Gear");
	_Materials->Add("Titanium Alloy");
	_Materials->Add("Memory Alloy");
	_Materials->Add("Rusted Clump");
	_Materials->Add("Machine Oil");
	_Materials->Add("Forlorn Necklace");
	_Materials->Add("Twisted Ring");
	_Materials->Add("Broken Earring");
	_Materials->Add("Pretty Choker");
	_Materials->Add("Metal Piercing");
	_Materials->Add("Subdued Bracelet");
	_Materials->Add("Technical Guide");
	_Materials->Add("Grubby Book");
	_Materials->Add("Thick Dictionary");
	_Materials->Add("Closed Book");
	_Materials->Add("Used Coloring Book");
	_Materials->Add("Old Schoolbook");
	_Materials->Add("Dirty Bag");
	_Materials->Add("Flashyh Hat");
	_Materials->Add("Leather Gloves");
	_Materials->Add("Silk Handkerchief");
	_Materials->Add("Leather Boots");
	_Materials->Add("Complex Machine");
	_Materials->Add("Elaborate Machine");
	_Materials->Add("Simple Machine");
	_Materials->Add("Stopped Clock");
	_Materials->Add("Broken Wristwatch");
	_Materials->Add("Rusty Kitchen Knife");
	_Materials->Add("Broken Saw");
	_Materials->Add("Dented Metal Bat");
	_Materials->Add("Shell");
	_Materials->Add("Gastropod");
	_Materials->Add("Bivalve");
	_Materials->Add("Seaweed");
	_Materials->Add("Empty Bottle");
	_Materials->Add("Driftwood");
	_Materials->Add("Pearl");
	_Materials->Add("Black Pearl");
	_Materials->Add("Crab");
	_Materials->Add("Starfish");
	_Materials->Add("Sea Turtle Egg");
	_Materials->Add("Broken Pottery");
	_Materials->Add("Desert Rose");
	_Materials->Add("Giant Egg");
	_Materials->Add("Damascus Steel");
	_Materials->Add("Eagle Egg");
	_Materials->Add("Chicken Egg");
	_Materials->Add("Mouse Tail");
	_Materials->Add("Lizard Tail");
	_Materials->Add("Deer Antler");

	// Key
	_Key->Add("Moon Key");
	_Key->Add("Star Key");
	_Key->Add("Light Key");
	_Key->Add("Darkness Key");
	_Key->Add("Fine Flour");
	_Key->Add("Coarse FLour");
	_Key->Add("Perfume Bottle");
	_Key->Add("Postman's Parcel");
	_Key->Add("Lover's Letter");
	_Key->Add("Water Filter");
	_Key->Add("Royal Compass");
	_Key->Add("Vapor Moss");
	_Key->Add("Valley Spoder Silk");
	_Key->Add("Animal Guidebook");
	_Key->Add("Ore Guidebook");
	_Key->Add("Plant Guidebook");
	_Key->Add("Red Book");
	_Key->Add("Blue Book");
	_Key->Add("Old Lady's Elixer");
	_Key->Add("Old Lady's Elixer+");
	_Key->Add("Parcel for The Aerie");
	_Key->Add("Parcel for Seafront");
	_Key->Add("Cookbook");
	_Key->Add("Parcel for Facade");
	_Key->Add("Max's Herbs");
	_Key->Add("Drifting Cargo");
	_Key->Add("Drifting Cargo 2");
	_Key->Add("Drifting Cargo 3");
	_Key->Add("Drifting Cargo 4");
	_Key->Add("Old Package");
	_Key->Add("Mermaid Tear");
	_Key->Add("Mandrake Leaf");
	_Key->Add("Energizer");
	_Key->Add("Tad Oil");
	_Key->Add("Sleep-B-Gone");
	_Key->Add("Antidote");
	_Key->Add("Gold Bracelet");
	_Key->Add("Elite Kitchen Knife");
	_Key->Add("Elevator Parts");
	_Key->Add("Dirty Treasure Map");
	_Key->Add("Restored Treasure Map");
	_Key->Add("Jade Hair Ornament");
	_Key->Add("Employee List");
	_Key->Add("Small Safe");
	_Key->Add("Safe Key");
	_Key->Add("Greaty Tree Root");
	_Key->Add("Eye of Power");
	_Key->Add("Ribbon");
	_Key->Add("Yonah's Ribbon");
	_Key->Add("Bronze Key");
	_Key->Add("Brass Key");
	_Key->Add("Boar Tusk");
	_Key->Add("Pressed Freesia");
	_Key->Add("Potted Freesia");
	_Key->Add("Fressia (Delivery)");
	_Key->Add("Pile of Junk");
	_Key->Add("Old Gold Coin");
	_Key->Add("Market Map");
	_Key->Add("AA Keycard");
	_Key->Add("KA Keycard");
	_Key->Add("SA Keycard");
	_Key->Add("TA Keycard");
	_Key->Add("NA Keycard");
	_Key->Add("HA Keycard");
	_Key->Add("MA Keycard");
	_Key->Add("YA Keycard");
	_Key->Add("RA Keycard");
	_Key->Add("WA Keycard");
	_Key->Add("Cultivator's Handbook");
	_Key->Add("Red Bag");
	_Key->Add("Lantern");
	_Key->Add("Empty Lantern");
	_Key->Add("Hold Key ");
	_Key->Add("Passageway Key");
	_Key->Add("Goat Key");
	_Key->Add("Lizard Key");
	_Key->Add("Unlocking Procedure Memo ");
	_Key->Add("Red Jewel");
	_Key->Add("Red Flowers ");
	_Key->Add("Apples");

	_Recovery->Sort();
	_Fishing->Sort();
	_Cultivation->Sort();
	_Materials->Sort();
	_Key->Sort();

	//Panel Components
	wxArrayString* ItemCategories = new wxArrayString();
	ItemCategories->Add("Recovery", 1);
	ItemCategories->Add("Cultivation", 1);
	ItemCategories->Add("Fishing", 1);
	ItemCategories->Add("Materials", 1);
	ItemCategories->Add("Key", 1);
	m_ItemCategoryComboBox = new wxComboBox(this, wxID_ANY, "", wxPoint(20, 20), wxSize(315, 25), *ItemCategories, 0, wxDefaultValidator, wxComboBoxNameStr);
	delete ItemCategories;
	m_ItemCategoryComboBox->Bind(wxEVT_COMBOBOX, &InventoryPanel::onChangeItemCategory, this);

	m_Items = new wxListBox(this, wxID_ANY, wxPoint(20, 60), wxSize(315, 300), *_Recovery, 0, wxDefaultValidator, wxListBoxNameStr);

	m_feedbacklbl = new wxStaticText(this, wxID_ANY, "", wxPoint(20, 430), wxSize(15, 150), wxALIGN_LEFT, wxStaticTextNameStr);

	//Buttons
	m_AddItems = new wxButton(this, wxID_ANY, wxString("Add Item"), wxPoint(20, 400), wxDefaultSize, 0, wxDefaultValidator, wxButtonNameStr);
	m_AddItems->Bind(wxEVT_BUTTON, &InventoryPanel::onAddItemPress, this);

	m_RemoveItems = new wxButton(this, wxID_ANY, wxString("Remove Item"), wxPoint(245, 400), wxDefaultSize, 0, wxDefaultValidator, wxButtonNameStr);
	m_RemoveItems->Bind(wxEVT_BUTTON, &InventoryPanel::onRemoveItemPress, this);

	m_Quantity = new wxTextCtrl(this, wxID_ANY, "1", wxPoint(100, 400), wxDefaultSize, 0, wxDefaultValidator, wxTextCtrlNameStr);

	this->SetBackgroundColour(wxColor(255, 255, 255));
	m_ItemCategoryComboBox->SetSelection(0);
}

InventoryPanel::~InventoryPanel()
{
}

void InventoryPanel::onAddItemPress(wxCommandEvent& evt)
{
	long quantity;
	m_Quantity->GetValue().ToLong(&quantity);

	int selection = m_Items->GetSelection();
	if (wxNOT_FOUND == selection)
	{
		wxMessageBox("Please select an item");
		return;
	}
	std::string name;
	switch (m_ItemCategoryComboBox->GetSelection())
	{
	case 0: //Recovery
		name = this->_Recovery->Item(selection);
		break;
	case 1: //Cultivation
		name = this->_Cultivation->Item(selection);
		break;
	case 2: //Fishing
		name = this->_Fishing->Item(selection);
		break;
	case 3: //Materials
		name = this->_Materials->Item(selection);
		break;
	case 4: //Key
		name = this->_Key->Item(selection);
		break;
	}

	if (hook->addItem(name, quantity) == 0)
	{
		m_feedbacklbl->SetForegroundColour(wxColor(102, 287, 106));
		m_feedbacklbl->SetLabel(name + " added");
	}
	else {
		m_feedbacklbl->SetForegroundColour(wxColor(239, 83, 80));
		m_feedbacklbl->SetLabel("Could not add " + name);
	}

}

void InventoryPanel::onRemoveItemPress(wxCommandEvent& evt)
{
	int selection = m_Items->GetSelection();
	if (wxNOT_FOUND == selection)
	{
		wxMessageBox("Please select an item");
		return;
	}
	std::string name;
	switch (m_ItemCategoryComboBox->GetSelection())
	{
	case 0: //Recovery
		name = this->_Recovery->Item(selection);
		break;
	case 1: //Cultivation
		name = this->_Cultivation->Item(selection);
		break;
	case 2: //Fishing
		name = this->_Fishing->Item(selection);
		break;
	case 3: //Materials
		name = this->_Materials->Item(selection);
		break;
	case 4: //Key
		name = this->_Key->Item(selection);
		break;
	}
	if (hook->removeItem(name) == 0)
	{
		m_feedbacklbl->SetForegroundColour(wxColor(102, 287, 106));
		m_feedbacklbl->SetLabel(name + " removed");
	}
	else {
		m_feedbacklbl->SetForegroundColour(wxColor(239, 83, 80));
		m_feedbacklbl->SetLabel("Could not remove " + name);
	}

}

void InventoryPanel::onChangeItemCategory(wxCommandEvent& evt)
{
	m_Items->Clear();
	switch (m_ItemCategoryComboBox->GetSelection())
	{
	case 0:
		m_Items->InsertItems(*_Recovery, 0);
		break;
	case 1:
		m_Items->InsertItems(*_Cultivation, 0);
		break;
	case 2:
		m_Items->InsertItems(*_Fishing, 0);
		break;
	case 3:
		m_Items->InsertItems(*_Materials, 0);
		break;
	case 4:
		m_Items->InsertItems(*_Key, 0);
		break;
	}
}
