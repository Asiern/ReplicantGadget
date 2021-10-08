#include "InventoryPanel.hpp"
wxBEGIN_EVENT_TABLE(InventoryPanel, wxPanel)
wxEND_EVENT_TABLE()

InventoryPanel::InventoryPanel(wxNotebook* parent, ReplicantHook* hook) : wxPanel(parent, wxID_ANY)
{
	this->hook = hook;

	this->_Recovery = new wxArrayString();
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

	this->_Cultivation = new wxArrayString();
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

	this->_Fishing = new wxArrayString();
	this->_Fishing->Add("Lugworm");
	this->_Fishing->Add("Earthworm");
	this->_Fishing->Add("Lure");
	this->_Fishing->Add("Sardine");
	this->_Fishing->Add("Carp");
	this->_Fishing->Add("Blowfish");
	this->_Fishing->Add("Bream");
	this->_Fishing->Add("Shark");
	this->_Fishing->Add("Blue Marlin");
	this->_Fishing->Add("Dunkleosteus");
	this->_Fishing->Add("Rainbow Trout");
	this->_Fishing->Add("Black Bass");
	this->_Fishing->Add("Giant Catfish");
	this->_Fishing->Add("Royal Fish");
	this->_Fishing->Add("Hyneria");
	this->_Fishing->Add("Sandfish");
	this->_Fishing->Add("Rhizodont");
	this->_Fishing->Add("Shaman FIsh");

	this->_Materials = new wxArrayString();
	this->_Materials->Add("Aquatic Plant");
	this->_Materials->Add("Deadwood");
	this->_Materials->Add("Rusty Bucket");
	this->_Materials->Add("Empty Can");
	this->_Materials->Add("Gold Ore");
	this->_Materials->Add("Silvert Ore");
	this->_Materials->Add("Copper Ore");
	this->_Materials->Add("Iron Ore");
	this->_Materials->Add("Crystal");
	this->_Materials->Add("Pyrite");
	this->_Materials->Add("Moldavite");
	this->_Materials->Add("Meteorite");
	this->_Materials->Add("Amber");
	this->_Materials->Add("Fluorite");
	this->_Materials->Add("Clay");
	this->_Materials->Add("Berries");
	this->_Materials->Add("Royal Fern");
	this->_Materials->Add("Tree Branch");
	this->_Materials->Add("Log");
	this->_Materials->Add("Natural Rubber");
	this->_Materials->Add("Ivy");
	this->_Materials->Add("Lichen");
	this->_Materials->Add("Mushroom");
	this->_Materials->Add("Sap");
	this->_Materials->Add("Mutton");
	this->_Materials->Add("Boar Meat");
	this->_Materials->Add("Woll");
	this->_Materials->Add("Boar Hide");
	this->_Materials->Add("Wolf Hide");
	this->_Materials->Add("Wolf Fang");
	this->_Materials->Add("Giant Spider Silk");
	this->_Materials->Add("Bat Fang");
	this->_Materials->Add("Bat Wing");
	this->_Materials->Add("Goat Meat");
	this->_Materials->Add("Goat Hide");
	this->_Materials->Add("Venison");
	this->_Materials->Add("Rainbow Spider Silk");
	this->_Materials->Add("Boar Liver");
	this->_Materials->Add("Scorpion Claw");
	this->_Materials->Add("Scorpion Tail");
	this->_Materials->Add("Dented Metal Board");
	this->_Materials->Add("Stripped Bolt");
	this->_Materials->Add("Broken Lens");
	this->_Materials->Add("Severed Cable");
	this->_Materials->Add("Broken Arm");
	this->_Materials->Add("Broken Antena");
	this->_Materials->Add("Broken Motor");
	this->_Materials->Add("Broken Battery");
	this->_Materials->Add("Mysterious Switch");
	this->_Materials->Add("Large Gear");
	this->_Materials->Add("Titanium Alloy");
	this->_Materials->Add("Memory Alloy");
	this->_Materials->Add("Rusted Clump");
	this->_Materials->Add("Machine Oil");
	this->_Materials->Add("Forlorn Necklace");
	this->_Materials->Add("Twisted Ring");
	this->_Materials->Add("Broken Earring");
	this->_Materials->Add("Pretty Choker");
	this->_Materials->Add("Metal Piercing");
	this->_Materials->Add("Subdued Bracelet");
	this->_Materials->Add("Technical Guide");
	this->_Materials->Add("Grubby Book");
	this->_Materials->Add("Thick Dictionary");
	this->_Materials->Add("Closed Book");
	this->_Materials->Add("Used Coloring Book");
	this->_Materials->Add("Old Schoolbook");
	this->_Materials->Add("Dirty Bag");
	this->_Materials->Add("Flashyh Hat");
	this->_Materials->Add("Leather Gloves");
	this->_Materials->Add("Silk Handkerchief");
	this->_Materials->Add("Leather Boots");
	this->_Materials->Add("Complex Machine");
	this->_Materials->Add("Elaborate Machine");
	this->_Materials->Add("Simple Machine");
	this->_Materials->Add("Stopped Clock");
	this->_Materials->Add("Broken Wristwatch");
	this->_Materials->Add("Rusty Kitchen Knife");
	this->_Materials->Add("Broken Saw");
	this->_Materials->Add("Dented Metal Bat");
	this->_Materials->Add("Shell");
	this->_Materials->Add("Gastropod");
	this->_Materials->Add("Bivalve");
	this->_Materials->Add("Seaweed");
	this->_Materials->Add("Empty Bottle");
	this->_Materials->Add("Driftwood");
	this->_Materials->Add("Pearl");
	this->_Materials->Add("Black Pearl");
	this->_Materials->Add("Crab");
	this->_Materials->Add("Starfish");
	this->_Materials->Add("Sea Turtle Egg");
	this->_Materials->Add("Broken Pottery");
	this->_Materials->Add("Desert Rose");
	this->_Materials->Add("Giant Egg");
	this->_Materials->Add("Damascus Steel");
	this->_Materials->Add("Eagle Egg");
	this->_Materials->Add("Chicken Egg");
	this->_Materials->Add("Mouse Tail");
	this->_Materials->Add("Lizard Tail");
	this->_Materials->Add("Deer Antler");

	this->_Key = new wxArrayString();
	this->_Key->Add("Moon Key");
	this->_Key->Add("Star Key");
	this->_Key->Add("Light Key");
	this->_Key->Add("Darkness Key");
	this->_Key->Add("Fine Flour");
	this->_Key->Add("Coarse FLour");
	this->_Key->Add("Perfume Bottle");
	this->_Key->Add("Postman's Parcel");
	this->_Key->Add("Lover's Letter");
	this->_Key->Add("Water Filter");
	this->_Key->Add("Royal Compass");
	this->_Key->Add("Vapor Moss");
	this->_Key->Add("Valley Spoder Silk");
	this->_Key->Add("Animal Guidebook");
	this->_Key->Add("Ore Guidebook");
	this->_Key->Add("Plant Guidebook");
	this->_Key->Add("Red Book");
	this->_Key->Add("Blue Book");
	this->_Key->Add("Old Lady's Elixer");
	this->_Key->Add("Old Lady's Elixer+");
	this->_Key->Add("Parcel for The Aerie");
	this->_Key->Add("Parcel for Seafront");
	this->_Key->Add("Cookbook");
	this->_Key->Add("Parcel for Facade");
	this->_Key->Add("Max's Herbs");
	this->_Key->Add("Drifting Cargo");
	this->_Key->Add("Drifting Cargo 2");
	this->_Key->Add("Drifting Cargo 3");
	this->_Key->Add("Drifting Cargo 4");
	this->_Key->Add("Old Package");
	this->_Key->Add("Mermaid Tear");
	this->_Key->Add("Mandrake Leaf");
	this->_Key->Add("Energizer");
	this->_Key->Add("Tad Oil");
	this->_Key->Add("Sleep-B-Gone");
	this->_Key->Add("Antidote");
	this->_Key->Add("Gold Bracelet");
	this->_Key->Add("Elite Kitchen Knife");
	this->_Key->Add("Elevator Parts");
	this->_Key->Add("Dirty Treasure Map");
	this->_Key->Add("Restored Treasure Map");
	this->_Key->Add("Jade Hair Ornament");
	this->_Key->Add("Employee List");
	this->_Key->Add("Small Safe");
	this->_Key->Add("Safe Key");
	this->_Key->Add("Greaty Tree Root");
	this->_Key->Add("Eye of Power");
	this->_Key->Add("Ribbon");
	this->_Key->Add("Yonah's Ribbon");
	this->_Key->Add("Bronze Key");
	this->_Key->Add("Brass Key");
	this->_Key->Add("Boar Tusk");
	this->_Key->Add("Pressed Freesia");
	this->_Key->Add("Potted Freesia");
	this->_Key->Add("Fressia(Delivery)");
	this->_Key->Add("Pile of Junk");
	this->_Key->Add("Old Gold Coin");
	this->_Key->Add("Market Map");
	this->_Key->Add("AA Keycard");
	this->_Key->Add("KA Keycard");
	this->_Key->Add("SA Keycard");
	this->_Key->Add("TA Keycard");
	this->_Key->Add("NA Keycard");
	this->_Key->Add("HA Keycard");
	this->_Key->Add("MA Keycard");
	this->_Key->Add("YA Keycard");
	this->_Key->Add("RA Keycard");
	this->_Key->Add("WA Keycard");
	this->_Key->Add("Cultivator's Handbook");
	this->_Key->Add("Red Bag");
	this->_Key->Add("Lantern");
	this->_Key->Add("Empty Lantern");
	this->_Key->Add("Hold Key");
	this->_Key->Add("Passageway Key");
	this->_Key->Add("Goat Key");
	this->_Key->Add("Lizard Key");
	this->_Key->Add("Unlocking Procedure Memo");
	this->_Key->Add("Red Jewel");
	this->_Key->Add("Red Flowers");
	this->_Key->Add("Apples");

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
