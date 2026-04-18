# 🤝 Contributing to DSA Mastery

Welcome! Thank you for your interest in contributing to **DSA Mastery**. Whether you're fixing a typo, adding a new algorithm, improving tests, or writing documentation, your contributions help thousands of developers master data structures & algorithms.

This guide outlines how to set up the project, follow coding standards, report issues, and submit pull requests.

---

## 📖 Table of Contents
- [🌟 Getting Started](#-getting-started)
- [📂 Project Structure](#-project-structure)
- [💻 Coding Standards](#-coding-standards)
- [🧪 Testing Guidelines](#-testing-guidelines)
- [📝 Documentation Requirements](#-documentation-requirements)
- [🐛 Reporting Issues](#-reporting-issues)
- [🔄 Pull Request Process](#-pull-request-process)
- [📜 Code of Conduct](#-code-of-conduct)
- [💬 Questions & Support](#-questions--support)

---

## 🌟 Getting Started

1. **Fork & Clone**
   ```bash
   git clone https://github.com/Vipul99999/dsa-mastery.git
   cd dsa-mastery
   ```

2. **Create a Branch**
   Always branch off `main`. Use descriptive prefixes:
   ```bash
   git checkout -b feat/add-segment-tree-cpp
   # or: fix/handle-empty-queue, docs/update-complexity-table
   ```

3. **Install Dependencies**
   Ensure you have the required runtimes & test frameworks:
   - Python ≥3.10: `pip install pytest black flake8`
   - Node.js ≥18: `npm install jest eslint prettier`
   - Java ≥17: `./gradlew test` (or Maven/JUnit setup)
   - C++ ≥17: `cmake` + `Catch2` + `clang-format`

4. **Verify Setup**
   ```bash
   pytest tests/ -v   # Python example
   ```

---

## 📂 Project Structure
Follow the existing directory layout to keep the repo organized:
```
📁 <algorithm-or-ds>/
├── 📄 README.md          # Concept, complexity, visuals
├── 📁 <language>/        # python/, java/, cpp/, js/
│   ├── <name>.<ext>
│   └── tests/
└── 📄 problems.md        # Curated practice links & solutions
```
> 📌 If adding a brand new topic, copy an existing folder as a template and adapt it.

---

## 💻 Coding Standards

| Rule | Details |
|------|---------|
| **Naming** | Clear, language-appropriate (`binary_search`, `BinarySearchTree`, `TwoSumSolver`) |
| **Complexity** | Always include `Time: O(...)` & `Space: O(...)` in top-level comments/docstrings |
| **Edge Cases** | Handle `None`/`null`, empty inputs, duplicates, min/max bounds, already sorted/reverse |
| **From Scratch** | Implement core algorithms manually. Standard library wrappers are allowed only if explicitly documented. |
| **Formatting** | Use project linters: `black` (Python), `eslint` (JS), `google-java-format` (Java), `clang-format` (C++) |
| **Type Safety** | Use type hints/generics where supported. Avoid `Any`/`var` when precise types are clear. |
| **No Copy-Paste** | Write original implementations. Credit external inspiration if used. |

---

## 🧪 Testing Guidelines

Every implementation **must** include a test suite covering:
- ✅ **Happy Path**: Typical inputs & expected outputs
- ✅ **Edge Cases**: Empty, single element, duplicates, extreme values
- ✅ **Performance/Stress**: Large inputs (if algorithm complexity is critical)
- ✅ **Idempotency/State**: For mutable structures, verify state changes correctly

**Run tests before pushing:**
```bash
pytest tests/ -v          # Python
npm test                  # JavaScript
./gradlew test            # Java
cmake --build . --target tests  # C++
```
> 🚩 PRs without passing tests or missing test coverage will be requested for updates.

---

## 📝 Documentation Requirements

When adding or updating a topic, ensure the `README.md` includes:
1. **Concept Summary**: 2–3 sentence explanation
2. **Step-by-Step Logic** or pseudocode
3. **Complexity Table**:
   | Operation | Time | Space |
   |-----------|------|-------|
   | Insert    | O(log n) | O(1) |
   | Search    | O(log n) | O(1) |
4. **Real-World Use Cases**
5. **Visual/ASCII Diagram** (highly encouraged)
6. **References**: Links to papers, textbooks, or authoritative articles

Keep explanations concise, beginner-friendly, and accurate.

---

## 🐛 Reporting Issues

Before opening an issue:
1. 🔍 Search existing issues to avoid duplicates.
2. 📝 Use the appropriate GitHub template (`Bug`, `Feature`, `Documentation`, `Question`).
3. Include:
   - Clear title & description
   - Steps to reproduce (for bugs)
   - Expected vs actual behavior
   - Language/runtime version & OS
   - Screenshots, logs, or code snippets

> 📌 **Bug labels**: `bug`, `priority: high/medium/low`  
> 📌 **Feature labels**: `enhancement`, `good first issue`, `help wanted`

---

## 🔄 Pull Request Process

1. **Sync with `main`**
   ```bash
   git fetch origin
   git checkout main
   git pull origin main
   git checkout your-branch
   git rebase main
   ```

2. **Commit Clearly** (Conventional Commits)
   ```
   feat: add iterative quicksort in Python
   fix: handle null root in BST deletion
   docs: update complexity table for Dijkstra
   test: add boundary tests for sliding window
   chore: update pytest config
   ```

3. **Open PR** against `main`
   - Fill out the PR template
   - Link related issue(s): `Closes #123` or `Fixes #456`
   - Attach screenshots/logs if UI/terminal output changed

4. **PR Checklist**
   - [ ] Code follows project standards
   - [ ] All tests pass locally & in CI
   - [ ] Documentation updated
   - [ ] No merge conflicts
   - [ ] License & attribution preserved

5. **Review & Merge**
   - Maintainers review within **3–5 business days**
   - Address feedback promptly; CI must stay green
   - Once approved, a maintainer will squash-merge

---

## 📜 Code of Conduct
This project adheres to the [Contributor Covenant Code of Conduct v2.1](https://www.contributor-covenant.org/version/2/1/).  
Be respectful, inclusive, and constructive. Harassment, discrimination, or toxic behavior will not be tolerated.

---

## 💬 Questions & Support
- 💡 **Discussions**: Use GitHub Discussions for learning paths, algorithm debates, or roadmap suggestions
- 🐛 **Bugs & Features**: Open an issue with the appropriate template
- 📧 **Maintainer Contact**: `maintainer@yourdomain.com` *(replace with yours)*
- 🌐 **Community Chat**: Join our Discord/Slack: `[invite-link]` *(replace with yours)*

---

🙏 **Thank you for contributing!** Every PR, issue, and discussion makes this repository better for learners worldwide.  
Happy coding, and may your solutions always run in `O(n log n)` or better. 🚀✨