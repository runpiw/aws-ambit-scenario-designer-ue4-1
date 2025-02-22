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

#pragma once

#include "Ambit/Mode/GltfExporterExternalInterface.h"

#include "GltfExporterExternalMock.generated.h"

/**
 * Mock class for GltfExport.h
 * To be used only during testing.
 */
UCLASS()
class UGltfExporterExternalMock : public UObject, public IGltfExporterExternalInterface
{
    GENERATED_BODY()
public:
    /** @inheritDoc */
    bool DoesExporterExist() override
    {
        return bExporterExists;
    }

    /** @inheritDoc */
    bool ExportBinary(UWorld* World, FBufferArchive& Buffer) override
    {
        return bExportResult;
    }

    /** @inheritDoc */
    bool WriteToFile(FBufferArchive& Buffer, const FString& Filename) override
    {
        return bWriteResult;
    }

    /**
     * Set the output values.
     *
     * @param ExporterExists The value to be returned by DoesExporterExist()
     * @param ExportResult The value to be returned by ExportBinary()
     * @param WriteResult The value to be returned by WriteToFile()
     */
    void SetOutputs(const bool ExporterExists, const bool ExportResult, const bool WriteResult)
    {
        bExporterExists = ExporterExists;
        bExportResult = ExportResult;
        bWriteResult = WriteResult;
    }

private:
    bool bExporterExists;
    bool bExportResult;
    bool bWriteResult;
};
