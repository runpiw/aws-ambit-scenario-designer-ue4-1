//   Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
//  
//   Licensed under the Apache License, Version 2.0 (the "License").
//   You may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//  
//       http://www.apache.org/licenses/LICENSE-2.0
//  
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

#include "GltfFileTypeDropdownMenu.h"

#include "Constant.h"

#include "AmbitMode.h"
#include "AmbitObject.h"

TArray<FString> FGltfFileTypeDropdownMenu::Values = {GltfFileType::KGltf, GltfFileType::KGlb};

FString FGltfFileTypeDropdownMenu::GetMenuItem()
{
    FAmbitMode* AmbitMode = FAmbitMode::GetEditorMode();
    check(AmbitMode);

    return AmbitMode->UISettings->GltfType;
}

void FGltfFileTypeDropdownMenu::OnChangeEvent(TSharedRef<IPropertyHandle> PropertyHandle, FString NewValue)
{
    ensure(PropertyHandle->SetValue(NewValue) == FPropertyAccess::Success);

    FAmbitMode* AmbitMode = FAmbitMode::GetEditorMode();
    check(AmbitMode);

    AmbitMode->UISettings->GltfType = NewValue;
}

TSharedRef<SWidget> FGltfFileTypeDropdownMenu::GetMenu(TSharedRef<IPropertyHandle> PropertyHandle)
{
    FMenuBuilder MenuBuilder(true, nullptr);

    for (int32 i = 0; i < Values.Num(); i++)
    {
        MenuBuilder.AddMenuEntry(FText::FromString(Values[i]), FText::GetEmpty(), FSlateIcon(),
                                 FExecuteAction::CreateStatic(&OnChangeEvent, PropertyHandle, Values[i]));
    }

    return MenuBuilder.MakeWidget();
}
