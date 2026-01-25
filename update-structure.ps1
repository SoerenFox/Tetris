$readme = "README.md"

if (!(Test-Path $readme)) {
  Write-Error "README.md not found"
  exit 1
}

# Top-level folders to include in the structure
$include = @("Assets", "Core")

function Get-Tree($path, $indent = 0) {
  Get-ChildItem $path -Directory | Sort-Object Name | ForEach-Object {
    $line = ("  " * $indent) + $_.Name + "/"
    $children = Get-Tree $_.FullName ($indent + 1)
    @($line) + $children
  }
}

$tree = @()
foreach ($dir in $include) {
  if (Test-Path $dir) {
    $tree += "$dir/"
    $tree += Get-Tree $dir 1
  }
}

# Build markdown code block safely
$treeText = $tree -join "`n"

$treeBlock = @"
```text
$treeText
"@

$content = Get-Content $readme -Raw

$pattern = "(?s)<!-- STRUCTURE:START -->.*?<!-- STRUCTURE:END -->"

$replacement = @"
<!-- STRUCTURE:START -->
$treeBlock
<!-- STRUCTURE:END -->
"@

if ($content -notmatch $pattern) {
  Write-Error "Structure markers not found in README.md"
  exit 1
}

$content -replace $pattern, $replacement |
  Set-Content $readme -Encoding UTF8

Write-Host "README structure updated successfully."
